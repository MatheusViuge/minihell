/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:13:13 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/16 22:16:22 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	flag_checker(char *arg)
{
	int	i;

	i = 1;
	if (arg[0] != '-')
		return (false);
	while (arg[i] == 'n')
		i++;
	if (arg[i] != '\0')
		return (false);
	return (true);
}

void	echo(t_node *ast)
{
	bool	flag;
	int		i;
	int		fd;

	if (ast->fd_in)
		close(ast->fd_in);
	if (ast->fd_out != 1)
		fd = ast->fd_out;
	else
		fd = STDOUT_FILENO;
	if (fd == -1)
		fd = 1;
	flag = false;
	i = 1;
	flag = flag_checker(ast->cmd[i]);
	if (flag)
		i++;
	while (ast->cmd[i])
	{
		ft_putstr_fd(ast->cmd[i++], fd);
		if (ast->cmd[i])
			ft_putchar_fd(' ', fd);
	}
	if (!flag)
		ft_putchar_fd('\n', fd);
}
