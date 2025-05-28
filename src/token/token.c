/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:22:13 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/24 19:22:14 by jesda-si         ###   ########.fr       */
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
	while (prompt[i])
	{
		curr = prompt + i;
		end = end_token(curr);
		if (!end)
			return (return_erro("Error", -1, data));
		token = create_token(prompt, curr, end, &len);
		if (!len)
		{
			i++;
			continue ;
		}
		if (!token)
			return (return_erro("Error", -1, data));
		add_token(&data->tokens, token);
		i += len;
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
	const char	*meta_char = "|<>\'\"";

	res = token_quote(str, &end);
	if (res == -1)
		return (NULL);
	else if (res == 1)
		return (end);
	i = -1;
	while (str[++i])
	{
		end = str + i;
		if (!ft_strchr(meta_char, *end) && !ft_isspace(*end))
			continue ;
		if (ft_isspace(*end) || i > 0)
			end--;
		else
			end = token_meta_char(end);
		break ;
	}
	return (end);
}

int	token_quote(char *str, char **end)
{
	char	*c;
	int		res;

	if (str[0] == '\'' || str[0] == '\"')
	{
		c = ft_strchr(str + 1, (int)str[0]);
		if (!c)
			return (-1);
		*end = c;
		res = token_quote((*end) + 1, end);
		if (res == -1)
			return (-1);
		return (1);
	}
	return (0);
}

char	*token_meta_char(char *end)
{
	while (*end && *end == *(end + 1))
		end = end + 1;
	if (!*end)
		end = end - 1;
	return (end);
}
