/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 18:57:09 by mviana-v          #+#    #+#             */
/*   Updated: 2025/05/19 19:20:03 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	verify_word(t_token *token, t_env **env);

bool	verify_metas(t_token *token, t_env **env)
{
	bool	is_valid;

	is_valid = true;
	if (token->type == PIPE)
	{
		if (token->next == NULL || ft_strlen(token->value) > 1)
		{//TO DO: Troca o fd de saida para o de erro
			printf("syntax error: unexpected token %c", token->value[1]);
			is_valid = false;
		}
	}
	else if (token->type == REDIR_IN || token->type == REDIR_OUT)
	{
		if (token->next == NULL || token->next->type != WORD)
		{
			ft_putendl_fd("syntax error: unexpected token", 2);
			is_valid = false;
		}
	}
	else if (token->type == HEREDOC || token->type == APPEND)
	return (is_valid);
}

bool	lexer(t_token **token, t_env **env)
{
	t_token *tmp;
	bool	is_valid;

	tmp = *token;
	is_valid = true;
	while (tmp)
	{
		if (tmp->type == WORD) //TO DO: Trocar a funcao que verifica se o token é um word, pela de expansao de variaveis
			is_valid = verify_word(tmp, env);
		else
			is_valid = verify_metas(tmp, env);
		tmp = tmp->next;
	}
		
	return (is_valid);
}
