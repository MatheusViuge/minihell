/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:14:45 by jesda-si          #+#    #+#             */
/*   Updated: 2025/07/26 12:57:16 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_env	*find_env(char *variable, t_env *env)
{
	t_env	*tmp;
	t_env	*node;

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
	return (str);
}
