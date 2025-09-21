/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:22:27 by mviana-v          #+#    #+#             */
/*   Updated: 2025/09/20 19:58:00 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ast_fd_closer(t_node *ast)
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

static void	exec_from_pipe(t_data *data, t_node *ast, char **path, char **env)
{
	int	i;

	i = 0;
	if (ast->type == BUILTIN)
	{
		free_matrix_env(&env);
		builtin_handler(data, ast);
		exec_cleaner(data, path, &env);
		return ;
	}
	while (path && path[i])
	{
		if (access(path[i], F_OK | X_OK) == 0)
			break ;
		i++;
	}
	if (!path[i])
		perror("Error on Exec_from_pipe"); // QUE ??????????????????????????
	dupper(ast->fd_in, ast->fd_out);
	ast_fd_closer(data->ast);
	if (execve(path[i], ast->cmd, env) == -1)
		perror("Error on Exec_from_pipe");
	exec_cleaner(data, path, &env);
}

static void	exec_pipe(t_data *data, t_node *ast, char ***env)
{
	int		pid;
	char	**path;

	if (!ast)
		return ;
	if (ast->type == PIPE)
	{
		exec_pipe(data, ast->left, env);
		exec_pipe(data, ast->right, env);
		return ;
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error: exec_pipe");
		return ;
	}
	path = path_finder(data->env, ast->cmd[0]);
	if (pid == 0)
		exec_from_pipe(data, ast, path, *env);
	path_cleaner(path);
	handle_pid(data, pid);
}

static void	single_exec(t_data *data, t_node *node, char ***env)
{
	int		pid;
	char	**path;

	if (node->type == BUILTIN)
	{
		free_matrix_env(env);
		builtin_handler(data, node);
		return ;
	}
	path = path_finder(data->env, node->cmd[0]);
	pid = fork();
	if (pid < 0)
	{
		perror("Error: single_exec");//return_erro("Fork failed", 1, data);
		return ;
	}
	if (pid == 0)
		exec(data, node, path, *env);
	handle_pid(data, pid);
	ast_fd_closer(data->ast);
	pid_wait(data, data->pids);
	path_cleaner(path);
}

void	exec_handler(t_data *data)
{
	char	**char_env;

	data->exit_code = 0;
	if (!data->ast)
		return ;
	handle_redirects(data, data->ast);
	handle_pipes(data->ast);
	char_env = env_transform(data->env);
	if (data->ast->type == PIPE)
		exec_pipe(data, data->ast, &char_env);
	else
		single_exec(data, data->ast, &char_env);
	free_matrix_env(&char_env);
	ast_fd_closer(data->ast);
	pid_wait(data, data->pids);
}
