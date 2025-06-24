/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:59:59 by mviana-v          #+#    #+#             */
/*   Updated: 2025/06/23 21:03:34 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	is_redir(t_token *token)
{
	return (token->type == REDIR_IN || token->type == REDIR_OUT
		|| token->type == HEREDOC || token->type == APPEND);
}

static bool	parser_validate(t_data *data)
{
	t_token	*tmp;
	bool	has_cmd;

	tmp = data->tokens;
	has_cmd = false;
	while (tmp)
	{
		if (is_redir(tmp))
			tmp = tmp->next->next;
		continue;
		if (tmp->type == WORD)
			has_cmd = true;
		tmp = tmp->next;
	}
	return (has_cmd);
}

bool	parser(t_data *data, char *input)
{
	bool	is_valid;

	is_valid = true;
	if (!input || !*input)
		return ;
	if (!(is_valid = token(data, input)))
		return (is_valid);	
	if (!(is_valid = lexer(&data->tokens, data)))
		return (is_valid);	
	if (is_valid = parser_validate(data))
		ast_builder(data, 0);
	return (is_valid);
}
