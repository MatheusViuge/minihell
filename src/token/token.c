/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:22:13 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/18 18:12:53 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	token(t_data *data, char *prompt)
{
	int		i;
	size_t	len;
	char	*curr;
	char	*end;
	t_token	*token;

	i = 0;
	while ((i == 0 || prompt[i - 1]) && prompt[i])
	{
		curr = prompt + i;
		end = end_token(curr);
		if (!end)
			return (return_erro("Error on tokenization", NULL, -1, data));
		token = create_token(prompt, curr, end, &len);
		if (!len)
			i++;
		else
		{
			if (!token)
				return (return_erro("Error on tokenization", NULL, -1, data));
			add_token(&data->tokens, token);
			i += len;
		}
	}
	return (true);
}

t_token	*create_token(char *prompt, char *start, char *end, size_t *size)
{
	char	*str;
	t_token	*token;

	*size = end - start + 1;
	if (!*size)
		return (NULL);
	str = ft_substr(prompt, start - prompt, *size);
	if (!str)
		return (NULL);
	token = new_token(str);
	if (!token)
		*size = -1;
	return (token);
}

char	*end_token(char *str)
{
	int			i;
	int			res;
	char		*end;
	const char	*meta_char = "|<>";

	end = str;
	i = -1;
	while (str[++i])
	{
		res = token_quote(str, &end, &i);
		if (res == -1)
			return (NULL);
		else if (res == 1
			&& !ft_isspace(*(end + 1)) && !ft_strchr(meta_char, *(end + 1)))
			return (end_token((end + 1)));
		else if (res == 1)
			return (end);
		end = str + i;
		if (!ft_strchr(meta_char, *end) && !ft_isspace(*end))
			continue ;
		end = token_meta_char(end, i);
		break ;
	}
	return (end);
}

int	token_quote(char *str, char **end, int *index)
{
	char	*c;

	while (str[*index] == '\'' || str[*index] == '\"')
	{
		c = ft_strchr(str + *index + 1, (int)str[*index]);
		if (!c)
			return (-1);
		*end = c;
		*index = *end - str + 1;
	}
	if (str + *index != *end)
		return (1);
	return (0);
}

char	*token_meta_char(char *end, int index)
{
	if (ft_isspace(*end) || index > 0)
	{
		end--;
		return (end);
	}
	while (*end && *end == *(end + 1))
		end = end + 1;
	if (!*end)
		end = end - 1;
	return (end);
}
