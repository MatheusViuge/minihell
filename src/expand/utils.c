/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 19:14:45 by jesda-si          #+#    #+#             */
/*   Updated: 2025/06/19 20:59:11 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*find_key(char *variable, t_env *env)
{
	char	*str;
	t_env	*tmp;

	str = NULL;
	if (keycmp(variable, *env, &str) == -1)
		return (NULL);
	tmp = env->next;
	while (!str && tmp != env)
	{
		if (keycmp(variable, *tmp, &str) == -1)
			return (NULL);
		tmp = tmp->next;
	}
	if (!str)
		str = ft_strdup("");
	return (str);
}

int	keycmp(char *variable, t_env env, char **str)
{
	if (!ft_strncmp(variable, env.key, ft_strlen(variable) + 1))
	{
		*str = ft_strdup(env.value);
		if (!*str)
			return (-1);
		return (1);
	}
	return (0);
}
