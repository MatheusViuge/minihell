/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:39:32 by jesda-si          #+#    #+#             */
/*   Updated: 2025/06/28 20:58:15 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	unset(char **args, t_env **head)
{
	t_env	*node;
	int		i;

	i = -1;
	while (args && args[i])
	{
		node = find_env(args[i], *head);
		if (!node)
			return (true);
		node->prev->next = node->next;
		node->next->prev = node->prev;
		if (node == *head)
			*head = node->next;
		free(node->key);
		free(node->value);
		free(node);
	}
	return (true);
}