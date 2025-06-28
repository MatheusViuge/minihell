/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:28:16 by mviana-v          #+#    #+#             */
/*   Updated: 2025/06/27 19:16:29 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**fill_cmd(t_token *token, int number)
{
	int	i;
	char	**cmd;

	i = 0;
	cmd = (char **)ft_calloc(sizeof(char *), number + 1);
	while ( i < number && token && token->type != PIPE)
	{
		if (token && is_redir(token))
			token = token->next->next;
		if (token->type == WORD)
		{
			cmd[i] = ft_strdup(token->value);
			if (!cmd[i])
			return (NULL); //Tenho que retornar error aqui.
			i++;
		}
		token = token->next;
	}
	return (cmd);
}

t_node	*create_node(int number, t_token *token, int redir_amount)
{
    t_node	*node;

    node = (t_node *)ft_calloc(sizeof(t_node), 1);
    if (!node)
		return (NULL);
	if (!(node->cmd = fill_cmd(token, number)))
	{
		free(node);
		return (NULL);
	}
	get_redirs(&node->redirs ,token, redir_amount);
	if (token->type == PIPE)
		node->type = PIPE;
	else
		node->type = COMMAND;
	node->fd_in = -1;
	node->fd_out = -1;
	return (node);
}

void	link_pipe_node(t_data *data, t_node *node)
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

void	link_node(t_data *data, t_node *node)
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

void	ast_builder(t_data *data)
{
	t_token	*tmp;
	t_token	*after_pipe;
	
	tmp = data->tokens;
	after_pipe = tmp;
	while (tmp)
	{
		if (tmp->type == PIPE)
		{
			after_pipe = tmp->next;
			handle_pipe_node(data, tmp);
		}
		else if (!tmp->next || tmp->next->type == PIPE)
			handle_command_node(data, &after_pipe);
		tmp = tmp->next;
	}
}
