/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:57:09 by mviana-v          #+#    #+#             */
/*   Updated: 2025/05/21 17:53:24 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static bool	verify_word(t_token *token, t_env **env);

static void	print_error(char *msg, bool *is_valid)
{
	ft_putendl_fd(msg, 2);
	*is_valid = false;
}

static void	verify_metas(t_token *token, bool *is_valid)
{
	if (token->type == REDIR_IN || token->type == REDIR_OUT)
	{
		if (token->next == NULL || token->next->type != WORD)
			print_error("syntax error: unexpected token", is_valid);
	}
	else if (token->type == HEREDOC || token->type == APPEND)
	{
		if (token->next == NULL || token->next->type != WORD)
			print_error("syntax error: unexpected token", is_valid);
	}
	else if (token->type == PIPE)
	{
		if (token->next == NULL || token->next == NULL)
			print_error("syntax error: unexpected token", is_valid);
	}
}

bool	lexer(t_token **token, t_env **env)
{
	t_token *tmp;
	bool	is_valid;

	tmp = *token;
	is_valid = true;
	while (tmp && is_valid)
	{
		if (tmp->type == WORD) //TO DO: Trocar a funcao que verifica se o token é um word, pela de expansao de variaveis
			is_valid = verify_word(tmp, env);
		else
			verify_metas(tmp, &is_valid);
		tmp = tmp->next;
	}
		
	return (is_valid);
}
