/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:02:08 by jesda-si          #+#    #+#             */
/*   Updated: 2025/07/26 13:06:24 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int		join_variable(char **value, t_expand *expand);
static t_expand	create_expand(int index, char *value, char *key, t_data *data);

bool	expand_variable(t_token *token, t_data *data)
{
	int		i;
	int		quote;

	quote = -1;
	i = -1;
	while (token->value[++i])
	{
		if ((token->value[i] == '\'' || token->value[i] == '\"'))
		{
			if (quote == -1)
				quote = token->value[i] & 1;
			else if (quote == (token->value[i] & 1))
				quote = -1;
		}
		if (token->value[i] != '$' || (token->value[i] == '$' && quote == 1))
			continue ;
		token->value = replace_variable(token->value, &i, data);
		if (!token->value)
			return (return_erro("Error", 2, data));
		if (!token->value[i])
			break ;
		if (((token->value[i] == '\'' || token->value[i] == '\"'))
			&& quote == (token->value[i] & 1))
			quote = -1;
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
		return (NULL);
	}
	*index = join_variable(&str, &expand);
	if (*index == -1)
		return (NULL);
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

static int	join_variable(char **value, t_expand *expand)
{
	char	*str;
	char	*tmp;
	int		len;

	str = ft_strjoin(expand->prev, expand->new);
	if (!str)
		return (-1);
	tmp = str;
	str = ft_strjoin(tmp, expand->next);
	free(tmp);
	if (!str)
		return (-1);
	free(*value);
	*value = str;
	len = ft_strlen(*value) - ft_strlen(expand->next);
	free(expand->prev);
	free(expand->next);
	free(expand->new);
	return (len);
}
