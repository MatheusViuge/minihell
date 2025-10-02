/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:02:29 by mviana-v          #+#    #+#             */
/*   Updated: 2025/09/20 22:47:01 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	redir_open(t_node *node, t_redir *redir, t_data *data)
{
	if (redir->type == REDIR_IN)
	{
		if (node->fd_in != -1)
			close(node->fd_in);
		node->fd_in = open(redir->name, O_RDONLY);
		if (node->fd_in < 0)
		{
			data->exit_code = 1;
			perror("Error: on redirects");
		}
	}
	else if (redir->type == REDIR_OUT)
	{
		if (node->fd_in != -1)
			close(node->fd_in);
		node->fd_out = open(redir->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (node->fd_out < 0)
		{
			data->exit_code = 1;
			perror("Error: on redirects");
		}
	}
	else if (redir->type == APPEND)
	{
		if (node->fd_in != -1)
			close(node->fd_in);
		node->fd_out = open(redir->name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (node->fd_out < 0)
		{
			data->exit_code = 1;
			perror("Error: on redirects");
		}
	}
}

static int	here_doc_handler(t_data *data, char *delimiter)
{
	int		pipefd[2];
	size_t	delimiter_size;
	char	*line;

	(void)data;
	delimiter_size = ft_strlen(delimiter);
	if (pipe(pipefd) == -1)
	{
		perror("Error: on redirects");
		return (-1);
	}
	while (1)
	{
		line = readline("> ");
		if (!line || ft_strncmp(line, delimiter, delimiter_size) == 0)
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, pipefd[1]);
		free(line);
	}
	close(pipefd[1]);
	return (pipefd[0]);
}

void	handle_redirects(t_data *data, t_node *node)
{
	t_redir	*redir;

	if (!node)
		return ;
	handle_redirects(data, node->left);
	handle_redirects(data, node->right);
	if (!node->redirs)
		return ;
	redir = node->redirs;
	while (redir)
	{
		if (redir->type != HEREDOC)
			redir_open(node, redir, data);
		else
			node->fd_in = here_doc_handler(data, redir->name);
		redir = redir->next;
	}
}
