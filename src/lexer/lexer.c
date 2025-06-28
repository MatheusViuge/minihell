/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:57:09 by mviana-v          #+#    #+#             */
/*   Updated: 2025/06/28 18:57:43 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_error(char *msg, bool *is_valid)
{
	ft_putendl_fd(msg, 2);
	*is_valid = false;
}

static void	verify_word(t_token *token, t_data *data, bool *is_valid)
{
	if (ft_strchr(token->value, '$') && (!token->prev
			|| token->prev->type != HEREDOC))
	{
		if (!expand_variable(token, data))
		{
			print_error("syntax error: unexpected token", is_valid);
			return ;
		}
	}
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
		else if ((token->prev->type != WORD && token->prev->type != HEREDOC)
			|| (token->next->type != WORD && token->next->type != HEREDOC))
			print_error("syntax error: unexpected token", is_valid);
	}
}

bool	lexer(t_token **token, t_data *data)
{
	t_token	*tmp;
	bool	is_valid;

	tmp = *token;
	is_valid = true;
	while (tmp && is_valid)
	{
		if (tmp->type == WORD)
			verify_word(tmp, data, &is_valid);
		else
			verify_metas(tmp, &is_valid);
		tmp = tmp->next;
	}
	return (is_valid);
}
