/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:02:08 by jesda-si          #+#    #+#             */
/*   Updated: 2025/08/22 15:12:13 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

static void	remove_quotes(char **value, int *index)
{
	int		start;
	char	*str;
	char	*tmp;
	char	*prev;

	start = ft_strnrchr_nbr(*value, (*value)[*index], *index - 1);
	prev = ft_substr(*value, 0, start);
	tmp = ft_substr(*value, start + 1, *index - start - 1);
	if (!tmp || !prev)
	{
		free(tmp);
		free(prev);
		free(*value);
		*value = NULL;
		return ;
	}
	str = ft_join_args(3, prev, tmp, &(*value)[*index + 1]);
	*index = ft_strlen(tmp) - 1;
	free(prev);
	free(tmp);
	free(*value);
	*value = str;
}

static void	set_quote(char **token, int *index, int *quote, char c)
{
	if (*quote == -1)
		*quote = c & 1;
	else if (*quote == (c & 1))
	{
		remove_quotes(token, index);
		*quote = -1;
	}
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

static t_expand	create_expand(int index, char *str, char *key, t_data *data)
{
	t_expand	expand;
	int			start;

	expand.prev = NULL;
	if (index > 0)
		expand.prev = ft_substr(str, 0, index);
	start = index + 1 + ft_strlen(key);
	expand.next = ft_substr(str, start, ft_strlen(str));
	if (!ft_strncmp(key, "?", 2))
		expand.new = ft_itoa(data->exit_code);
	else
		expand.new = find_value_env(key, data->env);
	return (expand);
}
