/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:02:29 by mviana-v          #+#    #+#             */
/*   Updated: 2025/08/19 18:40:10 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	redir_open(t_node *node, t_redir *redir)
{
	if (redir->type == REDIR_IN)
	{
		if (node->fd_in != -1)
			close(node->fd_in);
		node->fd_in = open(redir->name, O_RDONLY);
		if (node->fd_in < 0)
			perror("Error: on redirects");//return_erro("Failed to open input file", 1, NULL);
	}
	else if (redir->type == REDIR_OUT)
	{
		if (node->fd_in != -1)
			close(node->fd_in);
		node->fd_out = open(redir->name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (node->fd_out < 0)
			perror("Error: on redirects");//return_erro("Failed to open output file", 1, NULL);
	}
	else if (redir->type == APPEND)
	{
		if (node->fd_in != -1)
			close(node->fd_in);
		node->fd_out = open(redir->name, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (node->fd_out < 0)
			perror("Error: on redirects");//return_erro("Failed to open append file", 1, NULL);
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
		perror("Error: on redirects");//return_erro("Failed to create heredoc pipe", 1, data);
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

	if (!node || !node->redirs)
		return ;
	handle_redirects(data, node->left);
	handle_redirects(data, node->right);
	redir = node->redirs;
	while (redir)
	{
		if (redir->type != HEREDOC)
			redir_open(node, redir);
		else
			node->fd_in = here_doc_handler(data, redir->name);
		redir = redir->next;
	}
}
