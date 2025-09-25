/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:59:59 by mviana-v          #+#    #+#             */
/*   Updated: 2025/09/24 23:03:04 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	is_redir(t_token *token)
{
	return (token->type != PIPE && token->type != WORD);
}

void	print_tokens(t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		switch (tmp->type)
		{
		case WORD:
			printf("type: WORD        token: %s\n", tmp->value);
			break;
		case PIPE:
			printf("type: PIPE        token: %s\n", tmp->value);
			break;
		case REDIR_IN:
			printf("type: REDIR_IN    token: %s\n", tmp->value);
			break;
		case REDIR_OUT:
			printf("type: REDIR_OUT   token: %s\n", tmp->value);
			break;
		case APPEND:
			printf("type: APPEND      token: %s\n", tmp->value);
			break;
		case HEREDOC:
			printf("type: HEREDOC     token: %s\n", tmp->value);
			break;
		case AND:
			printf("type: AND         token: %s\n", tmp->value);
			break;
		case OR:
			printf("type: OR          token: %s\n", tmp->value);
			break;
		default:
			break;
		}
		tmp = tmp->next;
	}
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
