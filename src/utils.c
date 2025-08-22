/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 14:28:27 by jesda-si          #+#    #+#             */
/*   Updated: 2025/07/20 15:29:16 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	**convert_env(t_env *env)
{
	int		len;
	t_env	*current;
	char	**env_array;
	int		i;

	len = len_env(env);
	if (len == 0)
		return (NULL);
	env_array = malloc(sizeof(char *) * (len + 1));
	if (!env_array)
		return (NULL);
	i = 0;
	env_array[i] = ft_join_args(3, env->key, "=", env->value);
	if (!env_array[i++])
		return (free_env_array(env_array));
	current = env->next;
	while (current != env)
	{
		env_array[i] = ft_join_args(3, current->key, "=", current->value);
		if (!env_array[i++])
			return (free_env_array(env_array));
		current = current->next;
	}
	env_array[i] = NULL;
	return (env_array);
}

void	*free_env_array(char **env_array)
{
	int	i;

	if (!env_array)
		return (NULL);
	i = -1;
	while (env_array[++i])
		free(env_array[i]);
	free(env_array);
	return (NULL);
}
