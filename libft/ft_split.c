/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 17:07:46 by mviana-v          #+#    #+#             */
/*   Updated: 2024/10/14 20:11:50 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;
	int	check;

	i = 0;
	words = 0;
	check = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && check == 0)
		{
			check = 1;
			words++;
		}
		else if (s[i] == c && check == 1)
			check = 0;
		i++;
	}
	return (words);
}

static void	matrix_free(char **matrix, int line)
{
	while (line >= 0)
	{
		free(matrix[line]);
		line--;
	}
	free(matrix);
}

static void	matrix_fill(char const *s, char c, char **matrix, int words)
{
	int	line;
	int	index;
	int	l_index;

	line = 0;
	index = 0;
	l_index = 0;
	while (line < words)
	{
		while (s[index] == c)
			index++;
		l_index = index;
		while (s[index] != c && s[index] != '\0')
			index++;
		matrix[line] = ft_substr(s, l_index, index - l_index);
		if (!matrix[line])
		{
			matrix_free(matrix, line);
			break ;
		}
		line++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		words;

	if (!s)
		return (NULL);
	if (s[0] == '\0')
	{
		matrix = (char **)ft_calloc(1, sizeof(*matrix));
		return (matrix);
	}
	words = count_words(s, c);
	matrix = (char **)ft_calloc(words + 1, sizeof(*matrix));
	if (!matrix)
		return (NULL);
	matrix_fill(s, c, matrix, words);
	return (matrix);
}
