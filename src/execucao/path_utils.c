/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:05:44 by mviana-v          #+#    #+#             */
/*   Updated: 2025/09/20 21:37:09 by jesda-si         ###   ########.fr       */
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
			exit_error(NULL, NULL, &path);
		free(path[i]);
		path[i] = ft_strjoin(temp, cmd);
		if (!path[i])
			exit_error(NULL, NULL, &path);
		free(temp);
		i++;
	}
}

static char	**get_single_path(char **path, char *cmd)
{
	path = (char **)ft_calloc(sizeof(char *), 2);
	if (!path)
		exit_error(NULL, NULL, NULL);
	path[0] = ft_strdup(cmd);
	if (!path[0])
	{
		free(path);
		exit_error(NULL, NULL, NULL);
	}
	return (path);
}

char	**path_finder(t_env *env, char *cmd)
{
	char	**path;
	char	*path_value;

	if (!env || !cmd)
		return (NULL);
	path = NULL;
	if (access(&cmd[0], F_OK | X_OK) == 0)
		return (get_single_path(path, &cmd[0]));
	path_value = find_value_env("PATH", env);
	path = ft_split(path_value, ':');
	free(path_value);
	if (!path)
		exit_error(NULL, NULL, NULL);
	path_join(path, cmd);
	return (path);
}
