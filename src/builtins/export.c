/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:46:23 by mviana-v          #+#    #+#             */
/*   Updated: 2025/09/16 21:47:01 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	order_env(t_env **list);
static bool	set_env(t_env **head, char *arg);
static bool	print_env_export(t_env *head);

bool	export(char **args, t_env **head)
{
	int		i;
	char	*str;
	bool	success;

	if (!args || !*args)
		return (print_env_export(*head));
	i = -1;
	while (args[++i])
	{
		if (!(ft_isalpha(args[i][0]) || args[i][0] == '_'))
		{
			str = ft_sprintf("'%s' não é um identificador válido", args[i]);
			if (!str)
				return (false);
			ft_putendl_fd(str, 2);
			free(str);
			continue ;
		}
		success = set_env(head, args[i]);
		if (!success)
			return (false);
	}
	return (true);
}

static bool	set_env(t_env **head, char *arg)
{
	t_env	*node;
	char	**tmp;

	tmp = ft_split(arg, '=');
	if (!tmp)
		return (false);
	node = find_env(tmp[0], *head);
	if (node)
	{
		free(node->value);
		node->value = tmp[1];
		free(tmp[0]);
		free(tmp);
		return (true);
	}
	free_split(&tmp);
	add_env_node(new_node(arg), head);
	return (false);
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
		ft_printf("declare -x %s=%s\n", cpy[len]->key, cpy[len]->value);
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
