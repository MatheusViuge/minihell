/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 03:35:55 by mviana-v          #+#    #+#             */
/*   Updated: 2025/09/20 23:48:43 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	free_matrix_env(char ***env)
{
	int	i;

	if (!env || !*env)
		return ;
	i = 0;
	while ((*env)[i])
	{
		free((*env)[i]);
		(*env)[i] = NULL;
		i++;
	}
	free(*env);
	*env = NULL;
}

static size_t	get_env_size(t_env *env)
{
	size_t	size;
	t_env	*temp;

	temp = env->next;
	if (temp)
		size = 1;
	else
		size = 0;
	while (temp && temp != env)
	{
		size++;
		temp = temp->next;
	}
	return (size + 1);
}

char	**env_transform(t_env *env)
{
	char	**char_env;
	int		size;
	int		i;

	if (!env)
		return (NULL);
	size = get_env_size(env);
	char_env = (char **)malloc(sizeof(char *) * (size + 1));
	if (!char_env)
		exit_error(NULL, NULL, NULL);
	i = -1;
	while (env && ++i < size - 1)
	{
		char_env[i] = ft_join_args(3, env->key, "=", env->value);
		if (!char_env[i])
			exit_error(NULL, NULL, &char_env);
		env = env->next;
	}
	char_env[i] = NULL;
	return (char_env);
}
