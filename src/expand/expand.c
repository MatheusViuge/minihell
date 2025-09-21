/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:02:08 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/20 21:09:58 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

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
			exit_error(NULL, ft_strdup("Error: malloc failed"), NULL, NULL);
		if (token->value[i] != '$' || (token->value[i] == '$' && quote == 1))
			continue ;
		if (quote != 1)
			replace_variable(&token->value, &i, data);
		if (!token->value)
			exit_error(NULL, ft_strdup("Error: malloc failed"), NULL, NULL);
		if (!token->value[i])
			break ;
		if (token->value[i] == '\'' || token->value[i] == '\"')
			set_quote(&token->value, &i, &quote, token->value[i]);
		if (!token->value)
			exit_error(NULL, ft_strdup("Error: malloc failed"), NULL, NULL);
	}
	return (true);
}

void	replace_variable(char **value, int *index, t_data *data)
{
	int			i;
	int			start;
	char		*key;
	char		*tmp;
	const char	*meta_char = "_?";

	start = *index + 1;
	if ((*value)[start] && !(ft_isalpha((*value)[start])
		|| ft_strchr(meta_char, (*value)[start])))
		exit_error(NULL, ft_strdup("Error: malloc failed"), NULL, NULL);
	i = start;
	if ((*value)[i] && (*value)[i] == '?')
		i++;
	while ((*value)[i]
		&& (ft_isalnum((int)(*value)[i]) || (*value)[i] == '_'))
		i++;
	key = ft_substr(*value, start, i - start);
	if (!key)
		exit_error(NULL, ft_strdup("Error: malloc failed"), NULL, NULL);
	tmp = token_recreate(*value, key, index, data);
	if (!tmp)
		exit_error(NULL, ft_strdup("Error: malloc failed"), NULL, NULL);
	free(*value);
	*value = tmp;
}

char	*token_recreate(char *str, char *key, int *index, t_data *data)
{
	t_expand	expand;
	char		*tmp;

	if (!key)
		return (NULL);
	expand = create_expand(*index, str, key, data);
	free(key);
	if ((*index > 0 && !expand.prev) || !expand.new || !expand.next)
	{
		free(expand.prev);
		free(expand.next);
		free(expand.new);
		exit_error(NULL, ft_strdup("Error: malloc failed"), NULL, NULL);
	}
	tmp = ft_join_args(3, expand.prev, expand.new, expand.next);
	*index = ft_strlen(tmp) - ft_strlen(expand.next);
	free(expand.prev);
	free(expand.new);
	free(expand.next);
	return (tmp);
}
