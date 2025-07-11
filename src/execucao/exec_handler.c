/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:22:27 by mviana-v          #+#    #+#             */
/*   Updated: 2025/07/11 17:45:18 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	exec_pipe(t_data *data, t_node *ast)
{
	
}

void	single_exec(t_data *data, t_node *node)
{
	int		pid;
	int		status;
	char	**path;

	if (node->type == BUILTIN)
	{
		builtin_handler(data, node);
		return ;
	}
	path = path_finder(data->env, node->cmd[0]);
	pid = fork();
	if (pid < 0)
	{
		return_erro(data, 1, "Fork failed");
		return ;
	}
	if (pid == 0)
		exec(data, node, path);
	waitpid(pid, &status);
	data->exit_code = WEXITSTATUS(status);
}

void	exec_handler(t_data *data)
{
	if (data->exit_code != 0)
		return ;
	if (data->ast == NULL)
	{
		data->exit_code = 0;
		return ;
	}
	handle_redirects(data, data->ast);
	handle_pipes(data->ast);
	if (data->ast->type == PIPE)
		exec_pipe(data, data->ast);
	else
		single_exec(data, data->ast);
}
