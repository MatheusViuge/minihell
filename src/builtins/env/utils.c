/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:14:45 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/20 21:37:09 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_env	*find_env(char *variable, t_env *env)
{
	t_env	*tmp;
	t_env	*node;

	if (!env || !variable)
		return (NULL);
	node = NULL;
	if (!ft_strncmp(variable, env->key, ft_strlen(variable) + 1))
		node = env;
	tmp = env->next;
	while (!node && tmp != env)
	{
		if (!ft_strncmp(variable, tmp->key, ft_strlen(variable) + 1))
		{
			node = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	return (node);
}

char	*find_value_env(char *variable, t_env *env)
{
	t_env	*node;
	char	*str;

	node = find_env(variable, env);
	if (node)
		str = ft_strdup(node->value);
	else
		str = ft_strdup("");
	if (!str)
		exit_error(NULL, NULL, NULL);
	return (str);
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
