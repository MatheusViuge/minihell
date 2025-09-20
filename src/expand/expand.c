/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:02:08 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/20 15:41:39 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_expand	create_expand(int index, char *value, char *key, t_data *data);
static void		remove_quotes(char **value, int *index);
static void		set_quote(char **token, int *index, int *quote, char c);

bool	expand_variable(t_token *token, t_data *data)
{
	int		i;
	int		quote;

	quote = -1;
	i = -1;
	while (token->value[++i])
	{
		if ((token->value[i] == '\'' || token->value[i] == '\"'))
			set_quote(&token->value, &i, &quote, token->value[i]);
		if (!token->value)
			return (return_erro("Error", NULL, 2, data));
		if (token->value[i] != '$' || (token->value[i] == '$' && quote == 1))
			continue ;
		if (quote != 1)
			token->value = replace_variable(token->value, &i, data);
		if (!token->value)
			return (return_erro("Error", NULL, 2, data));
		if (!token->value[i])
			break ;
		if (token->value[i] == '\'' || token->value[i] == '\"')
			set_quote(&token->value, &i, &quote, token->value[i]);
		if (!token->value)
			return (return_erro("Error", NULL, 2, data));
	}
	return (true);
}

char	*replace_variable(char *value, int *index, t_data *data)
{
	int			i;
	int			start;
	char		*variable;
	const char	*meta_char = "_?";

	start = *index + 1;
	if (value[start]
		&& !(ft_isalpha(value[start]) || ft_strchr(meta_char, value[start])))
		return (NULL);
	i = start;
	if (value[i] && value[i] == '?')
		i++;
	else
	{
		while (value[i] && (ft_isalnum((int)value[i]) || value[i] == '_'))
			i++;
	}
	variable = ft_substr(value, start, i - start);
	if (!variable)
		return (NULL);
	return (token_recreate(value, variable, index, data));
}

char	*token_recreate(char *str, char *key, int *index, t_data *data)
{
	t_expand	expand;

	expand = create_expand(*index, str, key, data);
	free(key);
	if ((*index > 0 && !expand.prev) || !expand.new || !expand.next)
	{
		free(expand.prev);
		free(expand.next);
		free(expand.new);
		*index = -1;
		return (NULL);
	}
	free(str);
	str = ft_join_args(3, expand.prev, expand.new, expand.next);
	if (!str)
	{
		*index = -1;
		return (NULL);
	}
	*index = ft_strlen(str) - ft_strlen(expand.next);
	free(expand.prev);
	free(expand.next);
	free(expand.new);
	return (str);
}
