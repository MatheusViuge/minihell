/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:46:23 by mviana-v          #+#    #+#             */
/*   Updated: 2025/04/17 22:45:25 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"

static void	add_env_node(t_env *new_node, t_env *head)
{
	t_env	*current;
	t_env	*last;

	if (!new_node)
		return ;
	if (!head)
	{
		head = new_node;
		return ;
	}
	current = head;
	if (current->next == NULL)
	{
		current->next = new_node;
		current->prev = new_node;
		new_node->next = current;
		new_node->prev = current;
		return ;
	}
	last = current->prev;
	new_node->prev = last;
	new_node->next = current;
	current->prev = new_node;
	last->next = new_node;
}

void	create_env(char **env, t_env **head)
{
	int		i;

	i = 0;
	while (env[i])
	{
		add_env_node(new_node(env[i]), head);
		i++;
	}
	return (head);
}
