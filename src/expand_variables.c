/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 20:02:08 by jesda-si          #+#    #+#             */
/*   Updated: 2025/05/03 20:02:10 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	join_variable(char **value, char *prev, char *variable, char *next);

bool	expand_variable(t_token *token, t_data *data)
{
	char	*value;
	int		i;
	bool	res;

	value = token->value;
	if (*value == '\'')
		return (true);
	res = true;
	i = -1;
	while (token->value[++i])
	{
		if (token->value[i] != '$')
			continue ;
		res = replace_variable(&token->value, &i, data);
		if (!token->value[i] || !res)
			break ;
	}
	return (res);
}

bool	replace_variable(char **value, int *index, t_data *data)
{
	int			i;
	int			start;
	char		*variable;
	const char	*meta_char = "_?";

	start = *index + 1;
	if ((*value)[start] && !(ft_isalpha((*value)[start])
		|| ft_strchr(meta_char, (*value)[start])))
		return (true);
	i = start;
	if ((*value)[i] && (*value)[i] == '?')
		i++;
	else
	{
		while ((*value)[i]
				&& (ft_isalnum((int)(*value)[i]) || (*value)[i] == '_'))
			i++;
	}
	variable = ft_substr(*value, start, i - start);
	if (!variable)
		return (return_erro("Error", 2, data));
	return (token_recreate(value, variable, index, data));
}

bool	token_recreate(char **value, char *variable, int *index, t_data *data)
{
	char	*prev;
	char	*next;
	char	*str;
	int		start;

	prev = NULL;
	if (*index > 0)
		prev = ft_substr(*value, 0, *index);
	if (*index > 0 && !prev)
		return (return_erro("Error", 2, data));
	start = *index + 1;
	next = ft_substr(*value, start + ft_strlen(variable),
			ft_strlen(*value));
	if (!next)
	{
		free(prev);
		return (return_erro("Error", 2, data));
	}
	str = find_key(variable, data->env);
	free(variable);
	if (!str)
	{
		free(prev);
		free(next);
		return (return_erro("Error", 2, data));
	}
	*index = join_variable(value, prev, str, next);
	if (*index == -1)
		return (return_erro("Error", 2, data));
	return (true);
}

char	*find_key(char *variable, t_env *env)
{
	char	*str;
	t_env	*tmp;

	str = NULL;
	if (keycmp(variable, &str, *env) == -1)
		return (NULL);
	tmp = env->next;
	while (!str && tmp != env)
	{
		if (keycmp(variable, &str, *tmp) == -1)
			return (NULL);
		tmp = tmp->next;
	}
	if (!str)
		str = ft_strdup("");
	return (str);
}

int	keycmp(char *variable, char **str, t_env env)
{
	if (!ft_strncmp(variable, env.key, ft_strlen(variable) + 1))
	{
		*str = ft_strdup(env.value);
		if (!*str)
			return (-1);
		return (1);
	}
	return (0);
}

static int	join_variable(char **value, char *prev, char *variable, char *next)
{
	char	*str;
	char	*tmp;
	int		len;

	str = ft_strjoin(prev, variable);
	if (!str)
		return (-1);
	tmp = str;
	str = ft_strjoin(tmp, next);
	free(tmp);
	if (!str)
		return (-1);
	free(*value);
	free(prev);
	free(variable);
	free(next);
	*value = str;
	len = ft_strlen(*value);
	return (len);
}
