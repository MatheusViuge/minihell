/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ast_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 17:55:12 by mviana-v          #+#    #+#             */
/*   Updated: 2025/06/28 18:37:57 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_type_token	get_node_type(char *cmd)
{
	if (ft_strncmp(cmd, "cd", (ft_strlen("cd") + 1)) == 0)
		return (BUILTIN);
	else if (ft_strncmp(cmd, "echo", (ft_strlen("echo") + 1)) == 0)
		return (BUILTIN);
	else if (ft_strncmp(cmd, "exit", (ft_strlen("exit") + 1)) == 0)
		return (BUILTIN);
	else if (ft_strncmp(cmd, "export", (ft_strlen("export") + 1)) == 0)
		return (BUILTIN);
	else if (ft_strncmp(cmd, "pwd", (ft_strlen("pwd") + 1)) == 0)
		return (BUILTIN);
	else if (ft_strncmp(cmd, "unset", (ft_strlen("unset") + 1)) == 0)
		return (BUILTIN);
	else if (ft_strncmp(cmd, "env", (ft_strlen("env") + 1)) == 0)
		return (BUILTIN);
	return (COMMAND);
}

void	handle_pipe_node(t_data *data, t_token *token)
{
	t_node	*node;
	
	node = create_node(1, token, 0);
	if (ast_error_handler(&node, data, "Failed to create node"))
		return ;
	link_pipe_node(data, node);
}

int	redir_counter(t_token **token)
{
	int	i;

	i = 0;
	while (*token && is_redir(*token))
	{
		i++;
		*token = (*token)->next->next;
	}
	return (i);
}

void	get_redirs(t_redir **head ,t_token *token, int redir_amount)
{
	t_redir	*redir;
	t_redir	*tmp;

	tmp = NULL;
	while (token && redir_amount > 0 && token->type != PIPE)
	{
		if (is_redir(token))
		{
			if (!(redir = (t_redir *)ft_calloc(sizeof(t_redir), 1)))
				return ; // Handle error
			redir->type = token->type;
			if (!(redir->name = ft_strdup(token->next->value)))
				return ; // Handle error
			if (!*head)
				*head = redir;
			else
				tmp->next = redir;
			tmp = redir;
			token = token->next->next;
			redir_amount--;
		}
		else
			token = token->next;
	}
}

void	handle_command_node(t_data *data, t_token **token)
{
	int		count;
	int		redir_amount;
	t_token	*tmp;
	t_node	*node;

	count = 0;
	redir_amount = 0;
	tmp = *token;

	if (tmp && is_redir(tmp))
		redir_amount += redir_counter(&tmp);
	while (tmp && tmp->type == WORD)
	{
		count++;
		tmp = tmp->next;
		if (tmp && is_redir(tmp))
			redir_amount += redir_counter(&tmp);
	}
	node = create_node(count, *token, redir_amount); // Ajustar está função depois
	if (ast_error_handler(&node, data, "Failed to create node"))
		return ;
	link_node(data, node);
}
