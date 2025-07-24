/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:22:27 by mviana-v          #+#    #+#             */
/*   Updated: 2025/07/24 02:22:06 by mviana-v         ###   ########.fr       */
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
		return_erro(data, 1, "Fork failed");
		return ;
	}
	path = path_finder(data->env, ast->cmd[0]);
	if (pid == 0)
		exec(data, ast, path);
	path_cleaner(path);
	pid_handler(data, pid);
}

static void	single_exec(t_data *data, t_node *node)
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
	pid_handler(data, pid);
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
