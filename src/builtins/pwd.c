/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:58:56 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/16 22:31:07 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	pwd(t_node *ast, t_data *data)
{
	char	*cwd;
	int		fd;

	if (ast->fd_in != -1)
		close(ast->fd_in);
	if (ast->fd_out != -1)
		fd = ast->fd_out;
	else
		fd = STDOUT_FILENO;
	cwd = getcwd(NULL, 0);
	ft_putendl_fd(cwd, fd);
	free(cwd);
	data->exit_code = 0;
}
