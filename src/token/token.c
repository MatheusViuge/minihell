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

void	token(char *prompt, t_token **tokens)
{
	int		i;
	size_t	len;
	char	*curr;
	char	*end;
	char	*str;
	t_token	*token;

	i = 0;
	while (prompt[i])
	{
		curr = prompt + i;
		end = end_token(curr);
		if (!end)
		{
			free_tokens(tokens);
			return ;
		}
		len = (unsigned long)end - (unsigned long)curr + 1;
		if (!len)
		{
			i++;
			continue ;
		}
		str = ft_substr(prompt, curr - prompt, len);
		if (!str)
		{
			printf("ERROR\n");
			free_tokens(tokens);
			return ;
		}
		token = new_token(str);
		add_token(tokens, token);
		i += len;
	}
}

char	*end_token(char *str)
{
	int		i;
	char	*end;
	const char	*meta_char = "|<>\'\"";

	if (str[0] == '\'' || str[0] == '\"')
	{
		end = ft_strchr(str+1, (int)str[0]);
		if (!end)
		{
			ft_printf("ERROR\n");
			return (NULL);
		}
		return (end);
	}
	i = -1;
	while (str[++i])
	{
		end = str + i;
		if (!ft_strchr(meta_char, *end) && !ft_isspace(*end))
			continue ;
		if (ft_isspace(*end) || i > 0)
			end--;
		else
		{
			while (ft_strchr(meta_char, *end))
				end++;
		}
		break ;
	}
	return (end);
}
