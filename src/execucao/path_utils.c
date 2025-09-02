/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:05:44 by mviana-v          #+#    #+#             */
/*   Updated: 2025/08/25 21:51:34 by mviana-v         ###   ########.fr       */
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
		free(temp);
		i++;
	}
}

static char	**get_single_path(char **path, char *cmd)
{
	path = ft_calloc(sizeof(char *), 2);
	if (!path)
		return (NULL);
	path[0] = ft_strdup(cmd);
	if (!path[0])
	{
		free(path);
		return (NULL);
	}
	return (path);
}

char	**path_finder(t_env *env, char *cmd)
{
	char	**path;
	t_env	*current;

	if (!env || !cmd)
		return (NULL);
	current = env->next;
	path = NULL;
	if (access(&cmd[0], F_OK | X_OK) == 0)
		return (get_single_path(path, &cmd[0]));
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
