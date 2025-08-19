/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:46:23 by mviana-v          #+#    #+#             */
/*   Updated: 2025/07/07 18:52:42 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	env(t_env *head)
{
	t_env	*tmp;

	if (!head)
		return ;
	tmp = head;
	while (tmp != head->prev)
	{
		ft_printf("%s=\"%s\"\n", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	ft_printf("%s=\"%s\"\n", tmp->key, tmp->value);
}

t_env	*create_env(char **env)
{
	int		i;
	t_env	*head;

	head = NULL;
	i = 0;
	while (env[i])
	{
		add_env_node(new_node(env[i]), &head);
		i++;
	}
	return (head);
}

void	add_env_node(t_env *new_node, t_env **head)
{
	t_env	*current;
	t_env	*last;

	if (!new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	current = *head;
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

t_env	*new_node(char *str)
{
	t_env	*new;
	int		i;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	i = ft_strchr_nbr(str, '=');
	new->key = ft_substr(str, 0, i);
	if (!new->key)
	{
		free(new);
		return (NULL);
	}
	if (str[i])
		new->value = ft_substr(str, i + 1, ft_strlen(str) - i - 1);
	else
		new->value = NULL;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
