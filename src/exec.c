/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:04:39 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/20 17:37:25 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	builtin_handler(t_data *data, t_node *ast)
{
	(void)data;
	if (ast->type == BUILTIN)
	{
		if (ft_strncmp(ast->cmd[0], "cd", 3) == 0)
			cd(ast->cmd + 1, &data->env);
		else if (ft_strncmp(ast->cmd[0], "echo", 4) == 0)
			echo(ast);
		else if (ft_strncmp(ast->cmd[0], "env", 3) == 0)
			env(data->env, ast);
		else if (ft_strncmp(ast->cmd[0], "exit", 4) == 0)
			ft_exit(ast, data);
		else if (ft_strncmp(ast->cmd[0], "export", 6) == 0)
			export(ast, &data->env);
		else if (ft_strncmp(ast->cmd[0], "pwd", 3) == 0)
			pwd(ast, data);
		else if (ft_strncmp(ast->cmd[0], "unset", 6) == 0)
			unset(ast->cmd + 1, &data->env);
	}
}

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

void	exec_cleaner(t_data *data, char **path)
{
	int	exit_code;

	path_cleaner(path);
	exit_code = data->exit_code;
	free_data(data);
	exit(exit_code);
}

void	exec(t_data *data, t_node *node, char **path, char **env)
{
	int	i;

	i = 0;
	while (path && path[i])
	{
		if (access(path[i], F_OK | X_OK) == 0)
			break ;
		i++;
	}
	if (!path && !path[i])
		perror("Exec failed");//return_erro("Command not found", 127, data);
	dupper(node->fd_in, node->fd_out);
	if (path && execve(path[i], node->cmd, env) == -1)
		perror("Exec failed");//return_erro("Execution failed", 1, data);
	exec_cleaner(data, path);
}
