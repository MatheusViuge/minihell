/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:55:12 by mviana-v          #+#    #+#             */
/*   Updated: 2025/06/24 21:33:15 by mviana-v         ###   ########.fr       */
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

