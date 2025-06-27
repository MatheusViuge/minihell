/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:59:59 by mviana-v          #+#    #+#             */
/*   Updated: 2025/06/26 21:39:31 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	parser_validate(t_data *data)
{
	t_token	*tmp;
	bool	has_cmd;

	tmp = data->tokens;
	has_cmd = false;
	while (tmp)
	{
		if (is_redir(tmp))
		{
			tmp = tmp->next->next;
			continue;
		}
		if (tmp->type == WORD)
			has_cmd = true;
		tmp = tmp->next;
	}
	return (has_cmd);
}

bool	is_redir(t_token *token)
{
	return (token->type != PIPE && token->type != WORD);
}

bool	parser(t_data *data, char *input)
{
	bool	is_valid;

	is_valid = true;
	if (!input || !*input)
		return (false);
	if (!(is_valid = token(data, input)))
		return (is_valid);	
	if (!(is_valid = lexer(&data->tokens, data)))
		return (is_valid);	
	if ((is_valid = parser_validate(data)))
		ast_builder(data);
    print_ast(data->ast, 0);
	return (is_valid);
}
