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

void	expand_variables(t_token **tokens, t_env *env)
{
	t_token	*node;
	char	*value;
	int		i;

	node = *tokens;
	while (node)
	{
		value = node->value;
		if (*value == '\'')
		{
			node = node->next;
			continue ;
		}
		i = -1;
		while (node->value[++i])
		{
			if (node->value[i] != '$')
				continue ;
			replace_variable(&node->value, &i, env);
			if (!node->value[i])
				break ;
		}
		node = node->next;
	}
}

void	replace_variable(char **value, int *index, t_env *env)
{
	int			i;
	int			start;
	char		*variable;
	const char	*meta_char = "_?";

	start = *index + 1;
	if ((*value)[start] && ((*value)[start] == '(' || (*value)[start] == '{'))
		start++;
	if ((*value)[start] && !(ft_isalpha((*value)[start])
		|| ft_strchr(meta_char, (*value)[start])))
		return ;
	i = start;
	while ((*value)[i] && (ft_isalnum((int)(*value)[i]) || (*value)[i] == '_'))
		i++;
	i--;
	variable = ft_substr(*value, start, i - start + 1);
	if (!variable)
		return ;
	token_recreate(value, variable, index, env);
}

void	token_recreate(char **value, char *variable, int *index, t_env *env)
{
	char	*prev;
	char	*next;
	char	*str;
	int		start;

	prev = NULL;
	if (*index > 0)
		prev = ft_substr(*value, 0, *index);
	start = *index + 1;
	if ((*value)[start] == '(' || (*value)[start] == '{')
		start += 2;
	next = ft_substr(*value, start + ft_strlen(variable),
			ft_strlen(*value));
	if ((*value)[start - 2] == '(')
		str = exec_command(&variable, env);
	else
	{
		str = find_key(variable, env);
		free(variable);
	}
	if (!str)
		return ;
	*index = join_variable(value, prev, str, next);
	free(str);
	free(next);
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
	free(prev);
	if (!str)
		return (-1);
	tmp = str;
	str = ft_strjoin(tmp, next);
	free(tmp);
	if (!str)
		return (-1);
	free(*value);
	*value = str;
	len = ft_strlen(*value);
	return (len);
}
