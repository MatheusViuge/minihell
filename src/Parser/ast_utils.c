/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:55:12 by mviana-v          #+#    #+#             */
/*   Updated: 2025/06/26 22:43:45 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_pipe_node(t_data *data, t_token *token)
{
	t_node	*node;
	
	node = create_node(1, token);
	if (ast_error_handler(&node, data, "Failed to create node"))
		return ;
	link_pipe_node(data, node);
}

int	redir_counter(t_token **token)
{
	int	i;

	i = 0;
	while (*token && is_redir(*token))
	{
		i++;
		*token = (*token)->next->next;
	}
	return (i);
}

void	handle_command_node(t_data *data, t_token **token)
{
	int		count;
	int		redir_amount;
	t_token	*tmp;
	t_node	*node;

	count = 0;
	redir_amount = 0;
	tmp = *token;

	while (tmp && tmp->type == WORD)
	{
		count++;
		tmp = tmp->next;
		if (is_redir(tmp))
			redir_amount += redir_counter(&tmp);
	}
	node = create_node(count, *token, redir_amount); // Ajustar está função depois
	if (ast_error_handler(&node, data, "Failed to create node"))
		return ;
	link_node(data, node);
}
