/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:46:23 by mviana-v          #+#    #+#             */
/*   Updated: 2025/09/20 21:03:06 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void		order_env(t_env **list);
static void		set_env(t_env **head, char *arg);
static void		print_env_export(t_node *ast, t_env *head);
static t_env	**create_env_array(t_env *head);

void	export(t_node *ast, t_env **head)
{
	int		i;
	char	*str;

	if (!ast->cmd || !ast->cmd[1])
	{
		print_env_export(ast, *head);
		return ;
	}
	i = 0;
	while (ast->cmd[++i])
	{
		if (!ft_isalpha(ast->cmd[i][0]) && ast->cmd[i][0] != '_')
		{
			str = ft_sprintf("`%s': not a valid identifier", ast->cmd[i]);
			ft_putendl_fd(str, 2);
			free(str);
			continue ;
		}
		set_env(head, ast->cmd[i]);
	}
	return ;
}

static void	set_env(t_env **head, char *arg)
{
	t_env	*node;
	char	*tmp;
	int		i;

	i = ft_strchr_nbr(arg, '=');
	tmp = ft_substr(arg, 0, i);
	if (!tmp)
		exit_error(NULL, ft_strdup("Error: malloc failed"), NULL, NULL);
	node = find_env(tmp, *head);
	free(tmp);
	if (node)
	{
		free(node->value);
		node->value = ft_substr(arg, i + 1, ft_strlen(arg));
		if (!node->value)
			exit_error(NULL, ft_strdup("Error: malloc failed"), NULL, NULL);
		return ;
	}
	add_env_node(new_node(arg), head);
}

static void	print_env_export(t_node *ast, t_env *head)
{
	int		len;
	char	*str;
	char	*value;
	t_env	**env_array;
	int		fd;

	fd = define_fd(ast);
	env_array = create_env_array(head);
	len = -1;
	while (env_array[++len])
	{
		if (ft_strlen(env_array[len]->value))
			value = ft_sprintf("=\"%s\"", env_array[len]->value);
		else
			value = ft_strdup("");
		if (!value)
		{
			free(env_array);
			exit_error(NULL, ft_strdup("Error: malloc failed"), NULL, NULL);
		}
		str = ft_sprintf("declare -x %s%s", env_array[len]->key, value);
		free(value);
		if (!str)
		{
			free(env_array);
			exit_error(NULL, ft_strdup("Error: malloc failed"), NULL, NULL);
		}
		ft_putendl_fd(str, fd);
		free(str);
	}
	free(env_array);
	return ;
}

static t_env	**create_env_array(t_env *head)
{
	int		len;
	t_env	*tmp;
	t_env	**cpy;

	len = len_env(head);
	if (len == 0)
		return (NULL);
	cpy = (t_env **)ft_calloc(len + 1, sizeof(t_env *));
	if (!cpy)
		exit_error(NULL, ft_strdup("Error: malloc failed"), NULL, NULL);
	tmp = head;
	while (tmp != head->prev && --len >= 0)
	{
		cpy[len] = tmp;
		tmp = tmp->next;
	}
	cpy[--len] = tmp;
	order_env(cpy);
	return (cpy);
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
