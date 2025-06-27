/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 21:28:16 by mviana-v          #+#    #+#             */
/*   Updated: 2025/06/26 22:41:59 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	fill_cmd(char **cmd, t_token *token, int number, int redir_amount)
{
	int	i;

	i = 0;
	while ( i < number && token && token->type != PIPE)
	{
		if (token->type == WORD)
		{
			cmd[i] = ft_strdup(token->value);
			if (!cmd[i])
				return ; //Tenho que retornar error aqui.
			i++;
			token = token->next;
		}
		// else 
		// {
			
		// }
	}
}

t_node	*create_node(int number, t_token *token, int redir_amount)
{
    t_node	*node;

    node = (t_node *)ft_calloc(sizeof(t_node), 1);
    if (!node)
		return (NULL);
	node->cmd = (char **)ft_calloc(sizeof(char *), number + 1);
	fill_cmd(node->cmd, token, number, redir_amount);
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
		else 
			handle_command_node(data, &tmp);
		tmp = tmp->next;
	}
}
