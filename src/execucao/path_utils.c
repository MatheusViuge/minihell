/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:05:44 by mviana-v          #+#    #+#             */
/*   Updated: 2025/07/21 23:32:29 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	path_cleaner(char **path)
{
	int	i;

	if (!path)
		return ;
	i = 0;
	while (path[i])
	{
		free(path[i]);
		path[i] = NULL;
		i++;
	}
	free(path);
	path = NULL;
}

void	path_join(char **path, char *cmd)
{
	char	*temp;
	int		i;

	if (!path || !cmd)
		return ;
	i = 0;
	while (path[i])
	{
		if (!ft_strchr(cmd, '/'))
			temp = ft_strjoin(path[i], "/");
		else
			temp = ft_strdup(path[i]);
		if (!temp)
		{
			path_cleaner(path);
			return ;
		}
		free(path[i]);
		path[i] = ft_strjoin(temp, cmd);
		i++;
	}
}

char **path_finder(t_env *env, char *cmd)
{
	char **path;
	t_env *current;

	if (!env || !cmd)
		return (NULL);
	current = env->next;
	while (current != env)
	{
		if (ft_strncmp(current->key, "PATH", 4) == 0)
		{
			path = ft_split(current->value, ':');
			break ;
		}
		current = current->next;
	}
	if (!path)
		return (NULL);
	path_join(path, cmd);
	return (path);
}
