/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:32:33 by jesda-si          #+#    #+#             */
/*   Updated: 2025/06/22 16:01:52 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

void	free_env(t_env *head)
{
	t_env	*current;

	current = head;
	while (current)
	{
		free(current->key);
		free(current->value);
		if (current->next == head)
			break ;
		current = current->next;
		free(current->prev);
	}
	free(current);
}
