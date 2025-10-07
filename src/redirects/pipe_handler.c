/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:13:53 by mviana-v          #+#    #+#             */
/*   Updated: 2025/09/20 19:44:08 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	set_fd(int fd, int *target_fd)
{
	if (*target_fd != -1)
		close(*target_fd);
	*target_fd = fd;
}

void	handle_pipes(t_node *node)
{
	int	pipefd[2];

	if (node == NULL || node->type != PIPE)
		return ;
	if (pipe(pipefd) == -1)
	{
		perror("Error: pipe_handler");
		return ;
	}
	set_fd(pipefd[1], &node->left->fd_out);
	if (node->right->type != PIPE)
		set_fd(pipefd[0], &node->right->fd_in);
	else
	{
		set_fd(pipefd[0], &node->right->left->fd_in);
		handle_pipes(node->right);
	}
}
