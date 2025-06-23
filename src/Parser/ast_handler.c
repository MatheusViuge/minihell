/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:28:16 by mviana-v          #+#    #+#             */
/*   Updated: 2025/06/23 19:40:27 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	fill_cmd(char **cmd, t_token *token, int number)
{
	while (number >= 0 && token)
	{
		if (token->type == WORD || token->type == REDIR_IN
			|| token->type == REDIR_OUT || token->type == HEREDOC
			|| token->type == APPEND)
		{
			cmd[number] = ft_strdup(token->value);
			if (!cmd[number])
				return ;
			number--;
		}
		token = token->next;
	}
}

static t_node	*create_node(int number, t_token *token)
{
    t_node	*node;

    node = (t_node *)ft_calloc(sizeof(t_node), 1);
    if (!node)
		return (NULL);
	node->cmd = (char **)ft_calloc(sizeof(char *), number + 1);
	fill_cmd(node->cmd, token, number);
	if (!node->cmd)
	{
		free(node);
		return (NULL);
	}
	if (token->type == PIPE)
		node->type = PIPE;
	else
		node->type = COMMAND;
	node->fd_in = -1;
	node->fd_out = -1;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

static void	link_pipe_node(t_data *data, t_node *node)
{
	t_node	*tmp;
	
	tmp = data->ast;
	if (tmp->type != PIPE)
	{
		node->left = data->ast;
		data->ast = node;
		return ;
	}
	while (tmp->right->right)
		tmp = tmp->right;
	node->left = tmp->right;
	tmp->right = node;
}

static void	link_node(t_data *data, t_node *node)
{
	if (!data->ast)
	{
		data->ast = node;
		return ;
	}
	t_node	*tmp = data->ast;
	while (tmp->right)
		tmp = tmp->right;
	tmp->right = node;
}

void	ast_builder(t_data *data, int count)
{
	t_token	*tmp;
	t_node	*node;
	
	tmp = data->tokens;
	while (tmp)
	{
		if (tmp->type == PIPE)
		{
			node = create_node(1, tmp);
			if (ast_error_handler(node, data, "Failed to create node"))
				break ;
			link_pipe_node(data, node);
			count = 0;
		}
		else if (!tmp->next || tmp->next->type == PIPE)
		{
			node = create_node(count, tmp);
			if (ast_error_handler(node, data, "Failed to create node"))
				break ;
			link_node(data, node);
		}
		count++;
		tmp = tmp->next;
	}
}
