/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:22:27 by mviana-v          #+#    #+#             */
/*   Updated: 2025/07/25 16:47:04 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	ast_fd_closer(t_node *ast)
{
	if (!ast)
		return ;
	ast_fd_closer(ast->left);
	ast_fd_closer(ast->right);
	if (ast->fd_in != -1)
		close(ast->fd_in);
	if (ast->fd_out != -1)
		close(ast->fd_out);
}

static void	exec_from_pipe(t_data *data, t_node *ast, char **path)
{
	int	i;

	i = 0;
	if (ast->type == BUILTIN)
	{
		builtin_handler(data, ast);
		return ;
	}
	while (path && path[i])
	{
		if (access(path[i], F_OK | X_OK) == 0)
			break ;
		i++;
	}
	if (!path[i])
		return_erro("Command not found", 127, data);
	dupper(ast->fd_in, ast->fd_out);
	if (execve(path[i], ast->cmd, NULL) == -1)
		return_erro("Execution failed", 1, data);
	exec_cleaner(data, path);
}

static void	exec_pipe(t_data *data, t_node *ast)
{
	int		pid;
	char	**path;

	if (!ast)
		return ;
	if (ast->type == PIPE)
	{
		exec_pipe(data, ast->left);
		exec_pipe(data, ast->right);
		return ;
	}
	pid = fork();
	if (pid < 0)
	{
		return_erro("Fork failed", 1, data);
		return ;
	}
	path = path_finder(data->env, ast->cmd[0]);
	if (pid == 0)
		exec_from_pipe(data, ast, path);
	path_cleaner(path);
	handle_pid(data, pid);
}

static void	single_exec(t_data *data, t_node *node)
{
	int		pid;
	int		status;
	char	**path;

	status = 0;
	if (node->type == BUILTIN)
	{
		builtin_handler(data, node);
		return ;
	}
	path = path_finder(data->env, node->cmd[0]);
	pid = fork();
	if (pid < 0)
	{
		return_erro("Fork failed", 1, data);
		return ;
	}
	if (pid == 0)
		exec(data, node, path);
	handle_pid(data, pid);
	path_cleaner(path);
	data->exit_code = WEXITSTATUS(status);
}

void	exec_handler(t_data *data)
{
	if (data->exit_code != 0)
		return ;
	if (!data->ast)
		return ;
	handle_redirects(data, data->ast);
	handle_pipes(data->ast);
	if (data->ast->type == PIPE)
		exec_pipe(data, data->ast);
	else
		single_exec(data, data->ast);
	pid_wait(data, data->pids);
	ast_fd_closer(data->ast);
}
