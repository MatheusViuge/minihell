/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:57:09 by mviana-v          #+#    #+#             */
/*   Updated: 2025/05/27 23:26:36 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_error(char *msg, bool *is_valid)
{
	ft_putendl_fd(msg, 2);
	*is_valid = false;
}

static void	verify_metas(t_token *token, bool *is_valid)
{
	if (token->type == REDIR_IN || token->type == REDIR_OUT)
	{
		if (!token->next || token->next->type != WORD)
			print_error("syntax error: unexpected token", is_valid);
	}
	else if (token->type == HEREDOC || token->type == APPEND)
	{
		if (!token->next || token->next->type != WORD
			|| ft_strlen(token->value) > 2)
			print_error("syntax error: unexpected token", is_valid);
	}
	else if (token->type == PIPE)
	{
		if (!token->prev || !token->next || ft_strlen(token->value) > 1)
			print_error("syntax error: unexpected token", is_valid);
		else if (token->prev->type != WORD || token->next->type != WORD)
			print_error("syntax error: unexpected token", is_valid);
	}
}

bool	lexer(t_data *data)
{
	t_token	*tmp;
	bool	is_valid;

	tmp = data->tokens;
	is_valid = true;
	while (tmp && is_valid)
	{
		if (tmp->type == WORD && tmp->prev && tmp->prev->type != HEREDOC)
			is_valid = expand_variable(tmp, data);
		else
			verify_metas(tmp, &is_valid);
		tmp = tmp->next;
	}
	return (is_valid);
}
