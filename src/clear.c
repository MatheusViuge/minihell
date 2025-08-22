/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:32:33 by jesda-si          #+#    #+#             */
/*   Updated: 2025/07/20 15:26:10 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_data(t_data *data)
{
	free_env(&data->env);
	free_tokens(&data->tokens);
	free_ast(&data->ast);
}

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

void	free_env(t_env **head)
{
	t_env	*current;

	current = *head;
	while (current)
	{
		free(current->key);
		free(current->value);
		if (current->next == *head)
			break ;
		current = current->next;
		free(current->prev);
	}
	free(current);
	*head = NULL;
}

void	free_ast(t_node **ast)
{
	char	**cmd;
	int		i;

	if (!ast || !*ast)
		return ;
	cmd = (*ast)->cmd;
	free_ast(&(*ast)->left);
	free_ast(&(*ast)->right);
	i = 0;
	if ((*ast)->cmd)
	{
		while (cmd && cmd[i])
		{
			if (cmd[i])
				free(cmd[i]);
			i++;
		}
		free((*ast)->cmd);
		(*ast)->cmd = NULL;
	}
	if ((*ast)->redirs)
		free_redir_list((*ast)->redirs);
	free(*ast);
	*ast = NULL;
}

void	free_redir_list(t_redir *head)
{
	t_redir	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head->name);
		free(head);
		head = tmp;
	}
}
