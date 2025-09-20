/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/20 15:40:32 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/20 15:41:38 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	remove_quotes(char **value, int *index)
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
	*index = ft_strlen(prev) + ft_strlen(tmp) - 1;
	free(prev);
	free(tmp);
	free(*value);
	*value = str;
}

void	set_quote(char **token, int *index, int *quote, char c)
{
	if (*quote == -1)
		*quote = c & 1;
	else if (*quote == (c & 1))
	{
		remove_quotes(token, index);
		*quote = -1;
	}
}

t_expand	create_expand(int index, char *str, char *key, t_data *data)
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
