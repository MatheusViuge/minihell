/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:46:23 by mviana-v          #+#    #+#             */
/*   Updated: 2025/07/20 15:26:50 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	order_env(t_env **list);
static void	set_env(char **args, t_env **head);
static bool	print_env_export(t_env *head);

bool	export(char **args, t_env **head)
{
	if (!args || !*args)
		return (print_env_export(*head));
	set_env(args, head);
	return (true);
}

static void	set_env(char **args, t_env **head)
{
	int		i;
	t_env	*node;
	t_env	*tmp;
	char	*str;

	i = -1;
	while (args[++i])
	{
		if (ft_strncmp(args[i], "=", 2))
		{
			str = ft_join_args(3, "\'", args[i],
					"\' não é um identificador válido\n");
			ft_putendl_fd(str, 2);
			free(str);
			continue ;
		}
		node = find_env(args[i], *head);
		if (node)
		{
			tmp = new_node(*args);
			free(node->value);
			node->value = tmp->value;
			free(node->key);
			free(node);
			continue ;
		}
		add_env_node(new_node(args[i]), head);
	}
}

static bool	print_env_export(t_env *head)
{
	int		len;
	t_env	*tmp;
	t_env	**cpy;

	if (!head)
		return (true);
	len = len_env(head);
	if (len < 2)
		return (true);
	cpy = ft_calloc(len + 1, sizeof(t_env *));
	if (!cpy)
		return (false);
	tmp = head;
	while (tmp != head->prev && --len > 0)
	{
		cpy[len] = tmp;
		tmp = tmp->next;
	}
	cpy[len--] = tmp;
	order_env(cpy);
	while (cpy[++len])
		ft_printf("declare -x %s=\"%s\"\n", cpy[len]->key, cpy[len]->value);
	free(cpy);
	return (true);
}

static void	order_env(t_env **list)
{
	int		i;
	int		j;
	int		len;
	t_env	*node;
	t_env	*prev;

	i = 0;
	while (list && list[++i])
	{
		j = i;
		while (j > 0)
		{
			node = list[j];
			prev = list[j - 1];
			len = ft_strlen(node->key) + 1;
			if (prev && ft_strncmp(node->key, prev->key, len) < 0)
			{
				list[j] = prev;
				list[--j] = node;
			}
			else
				break ;
		}
	}
}

int	len_env(t_env *head)
{
	int		len;
	t_env	*tmp;

	if (!head)
		return (0);
	len = 1;
	tmp = head->next;
	while (tmp != head)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
