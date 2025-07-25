/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:04:39 by jesda-si          #+#    #+#             */
/*   Updated: 2025/07/25 16:36:11 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	builtin_handler(t_data *data, t_node *ast)
{
	(void)data;
	if (ast->type == BUILTIN)
	{
		if (ft_strncmp(ast->cmd[0], "cd", 3) == 0)
			printf("cd command not implemented\n");//cd_handler(data, ast);
		else if (ft_strncmp(ast->cmd[0], "echo", 4) == 0)
			printf("echo command not implemented\n");//echo_handler(data, ast);
		else if (ft_strncmp(ast->cmd[0], "env", 3) == 0)
			printf("env command not implemented\n");//env_handler(data, ast);
		else if (ft_strncmp(ast->cmd[0], "exit", 4) == 0)
			printf("exit command not implemented\n");//exit_handler(data, ast);
		else if (ft_strncmp(ast->cmd[0], "export", 6) == 0)
			printf("export command not implemented\n");//export_handler(data, ast);
		else if (ft_strncmp(ast->cmd[0], "pwd", 3) == 0)
			printf("pwd command not implemented\n");//pwd_handler(data, ast);
		else if (ft_strncmp(ast->cmd[0], "unset", 6) == 0)
			printf("unset command not implemented\n");//unset_handler(data, ast);
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
		return_erro("Command not found", 127, data);
	dupper(node->fd_in, node->fd_out);
	if (execve(path[i], node->cmd, NULL) == -1)
		return_erro("Execution failed", 1, data);
	exec_cleaner(data, path);
}
