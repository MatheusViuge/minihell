/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:56:39 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/18 19:38:27 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_type_token	type_token(char *token)
{
	const char	*meta_char = "|<>";

	if (*token == meta_char[0])
		return (PIPE);
	if (token[0] == meta_char[1] && (token[1] && token[1] == meta_char[1]))
		return (HEREDOC);
	if (token[0] == meta_char[1])
		return (REDIR_IN);
	if (token[0] == meta_char[2] && (token[1] && token[1] == meta_char[2]))
		return (APPEND);
	if (token[0] == meta_char[2])
		return (REDIR_OUT);
	return (WORD);
}

t_token	*new_token(char *str)
{
	t_token	*new;

	new = ft_calloc(1, sizeof(t_token));
	if (!new)
		return (NULL);
	new->value = str;
	new->type = type_token(str);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	size_tokens(t_token *tokens)
{
	int	i;

	i = 0;
	while (tokens)
	{
		tokens = tokens->next;
		i++;
	}
	return (i);
}

t_token	*last_token(t_token *tokens)
{
	while (tokens && tokens->next)
		tokens = tokens->next;
	return (tokens);
}

void	add_token(t_token **tokens, t_token *new)
{
	t_token	*last;

	if (!new)
		return ;
	if (!*tokens)
	{
		*tokens = new;
		return ;
	}
	last = last_token(*tokens);
	last->next = new;
	new->prev = last;
}

bool		token_error(char *prompt, t_data *data)
{
	char	*str;

	str = ft_sprintf("syntax error near unexpected token `%s`\n",
			prompt);
	if (!str)
		return (false);
	ft_putstr_fd(str, STDERR_FILENO);
	free(str);
	data->exit_code = 1;
	free_tokens(&data->tokens);
	data->tokens = NULL;
	return (true);
}
