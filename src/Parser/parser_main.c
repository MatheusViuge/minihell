/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:59:59 by mviana-v          #+#    #+#             */
/*   Updated: 2025/07/07 15:36:22 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_redir(t_token *token)
{
	return (token->type != PIPE && token->type != WORD);
}

bool	parser(t_data *data, char *input)
{
	if (!input || !*input)
		return (false);
	if (!token(data, input))
		return (false);
	if (!lexer(data))
		return (false);
	ast_builder(data);
	print_ast(data->ast, 0);
	return (true);
}
