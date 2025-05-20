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

void	replace_variable(char **value, int *index, t_env *env);

void	expand_variables(t_token **tokens, t_env *env)
{
	t_token	*node;
	char	*value;
	// char	*str;
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
		while (value[++i])
		{
			if (value[i] != '$')
				continue ;
			if (value[i + 1] && !ft_isspace((int)value[i + 1]))
				replace_variable(&node->value, &i, env);
			if (!value[i])
				break ;
		}
		node = node->next;
	}
	
}

void	replace_variable(char **value, int *index, t_env *env)
{
	int		i;
	int		len;
	char	*variable;
	char	*prev;
	char	*next;
	char	*str;
	t_env	*tmp;

	i = *index + 1;
	while ((*value)[i])
	{
		if (!ft_isalnum((int)(*value)[i]))
			break ;
		i++;
	}
	if (!(*value)[i])
		i--;
	len = i - *index;
	variable = ft_substr(*value, *index + 1, len);
	if (!variable)
		return ;
	str = NULL;
	tmp = env->next;
	while (tmp != env)
	{
		if (!ft_strncmp(variable, tmp->key, len + 1))
		{
			str = ft_strdup(tmp->value);
			if (!str)
				return ;
			break ;
		}
		tmp = tmp->next;
	}
	if (!str && !ft_strncmp(variable, tmp->key, len + 1))
	{
		str = ft_strdup(tmp->value);
		if (!str)
			return ;
	}
	if (!str)
	{
		str = ft_strdup("");
		if (!str)
			return ;
	}
	prev = NULL;
	if (*index > 0)
		prev = ft_substr(*value, 0, *index - 1);
	next = ft_substr(*value, *index + len + 1, ft_strlen(*value));
	free(variable);
	variable = ft_strjoin(prev, str);
	i = ft_strlen(variable) + 1;
	free(prev);
	free(str);
	str = variable;
	variable = ft_strjoin(variable, next);
	free(str);
	free(next);
	*index = i;
	*value = variable;
}