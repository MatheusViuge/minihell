/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 23:22:38 by jesda-si          #+#    #+#             */
/*   Updated: 2025/06/29 13:51:34 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_index(const char *s, int c, int start);
static void	strsctr(char const *s, int c, char **strs, int size);
static void	free_strs(char **strs, int i);

char	**ft_split(char const *s, char c)
{
	int		i;
	int		size;
	char	**strs;

	if (!s)
		return (NULL);
	size = 0;
	i = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			size++;
		else if (s[i] == c && s[i + 1] != c && s[i + 1])
			size++;
		i++;
	}
	strs = (char **)ft_calloc(sizeof(char *), (size + 1));
	if (!strs)
		return (NULL);
	strsctr(s, c, strs, size);
	return (strs);
}

static void	strsctr(char const *s, int c, char **strs, int size)
{
	int		i;
	int		j;
	int		start;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	while (i < size)
	{
		start = find_index(&s[j], c, 1) + j;
		j += find_index(&s[j], c, 0) + 1;
		len = j - start;
		if (len > 0)
		{
			str = (char *)ft_calloc(sizeof(char), len);
			if (!str)
			{
				free_strs(strs, i);
				return ;
			}
			ft_strlcpy(str, &s[start], len);
			strs[i++] = str;
		}
	}
}

static int	find_index(const char *s, int c, int start)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (start && s[i] != (char)c)
			break ;
		else if (!start && s[i] == (char)c)
			break ;
		i++;
	}
	return (i);
}

static void	free_strs(char **strs, int i)
{
	int	j;

	j = 0;
	while (j < i)
		free(strs[j++]);
	free(strs);
}
