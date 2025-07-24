/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:04:39 by jesda-si          #+#    #+#             */
/*   Updated: 2025/07/22 20:22:39 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	dupper(int fd_in, int fd_out)
{
	if (fd_in != -1)
	{
		dup2(fd_in, STDIN_FILENO);
		close(fd_in);
	}
	if (fd_out != -1)
	{
		dup2(fd_out, STDOUT_FILENO);
		close(fd_out);
	}
}

static void	exec_cleaner(t_data *data, char **path)
{
	int	exit_code;

	path_cleaner(path);
	exit_code = data->exit_code;
	free_data(data);
	exit(exit_code);
}

void	exec(t_data *data, t_node *node, char **path)
{
	int	i;

	i = 0;
	while (path && path[i])
	{
		if (access(path[i], F_OK | X_OK) == 0)
			break ;
		i++;
	}
	if (!path[i])
		exec_exit(data, 127, "Command not found");
	dupper(node->fd_in, node->fd_out);
	if (execve(path[i], node->cmd, data->env) == -1)
		return_erro(data, 1, "Execution failed");
	exec_cleaner(data, path);
}
