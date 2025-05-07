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

void		replace_variable(char **value, int *index, t_env *env);
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
			if (node->value[i + 1] && !ft_isspace((int)value[i + 1]))
				replace_variable(&node->value, &i, env);
			if (!node->value[i])
				break ;
		}
		node = node->next;
	}
}

void	replace_variable(char **value, int *index, t_env *env)
{
	int		i;
	char	*variable;
	char	*prev;
	char	*next;
	char	*str;

	i = *index + 1;
	while ((*value)[i] && !ft_isalnum((int)(*value)[i]))
		i++;
	if (!(*value)[i])
		i--;
	variable = ft_substr(*value, *index + 1, i - *index);
	if (!variable)
		return ;
	prev = NULL;
	if (*index > 0)
		prev = ft_substr(*value, 0, *index);
	next = ft_substr(*value, *index + ft_strlen(variable) + 1,
			ft_strlen(*value));
	str = find_key(variable, env);
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
