/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:47:55 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/05 16:35:42 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_index(char const *s1, char const *set);
static int	end_index(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		size;
	char	*str;

	start = start_index(s1, set);
	end = end_index(s1, set);
	size = end - start + 2;
	str = ft_substr(s1, start, size);
	return (str);
}

static int	start_index(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	return (i);
}

static int	end_index(char const *s1, char const *set)
{
	int	i;

	i = (int)ft_strlen(s1) - 1;
	while (s1[i] && ft_strchr(set, s1[i]))
		i--;
	return (i - 1);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	const char	*str;
	const char	*set;

	if (c == 3)
	{
		str = v[1];
		set = v[2];
		printf("str: %s \nset: %s \nres: %s\n", str, set, ft_strtrim(str, set));
	}
	return (0);
}*/
