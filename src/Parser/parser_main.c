/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:59:59 by mviana-v          #+#    #+#             */
/*   Updated: 2025/06/27 19:39:43 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


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
	ast_builder(data);
    print_ast(data->ast, 0);
	return (is_valid);
}
