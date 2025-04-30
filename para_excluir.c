/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   para_excluir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:56:25 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/30 15:56:28 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minishell.h"

void	free_tokens(t_token **tokens)
{
	t_token	*tmp;
	t_token	*next;

	tmp = *tokens;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->value);
		free(tmp);
		tmp = next;
	}
	*tokens = NULL;
}

void	print_tokens(t_token *tokens)
{
	const char	*types[4] = {"word", "pipe", "redirect input",
		"redirect output"};

	if (!tokens)
		return ;
	while (tokens)
	{
		printf("token: %s\ntipo: %s\n\n", tokens->value, types[tokens->type]);
		tokens = tokens->next;
	}
}
