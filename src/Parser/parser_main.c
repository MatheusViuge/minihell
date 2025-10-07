/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:59:59 by mviana-v          #+#    #+#             */
/*   Updated: 2025/09/20 22:48:00 by mviana-v         ###   ########.fr       */
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
	{
		data->exit_code = 2;
		return (false);
	}
	ast_builder(data);
	return (true);
}
