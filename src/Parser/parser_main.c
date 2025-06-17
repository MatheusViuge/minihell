/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:59:59 by mviana-v          #+#    #+#             */
/*   Updated: 2025/06/17 17:19:34 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_node	*create_args(int number)
{
    t_node	*node;

    node = (t_node *)ft_calloc(sizeof(t_node), 1);
    if (!node)
		return (NULL);
	node->cmd = (char **)ft_calloc(sizeof(char *), number + 1);
	if (!node->cmd)
	{
		free(node);
		return (NULL);
	}
	node->type = COMMAND;
	node->fd_in = STDIN_FILENO;
	node->fd_out = STDOUT_FILENO;
	node->left = NULL;
	node->right = NULL;
	return (node);
}

int	parser(t_data *data)
{
	t_token	*tmp;
	bool	is_valid;

	tmp = data->tokens;
	while (tmp)
	{
		/* Desenvolver a lógica para o tratamento para o dos tokens */
	}
	return (0);
}
