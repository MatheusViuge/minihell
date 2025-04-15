/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:40:05 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/03 21:09:44 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	char	*str;

	size_s1 = (int)ft_strlen(s1);
	size_s2 = (int)ft_strlen(s2);
	str = (char *)ft_calloc(sizeof (char), (size_s1 + size_s2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, size_s1 + 1);
	ft_strlcat(str, s2, size_s1 + size_s2 + 1);
	return (str);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	const char	*s1;
	const char	*s2;

	if (c == 3)
	{
		s1 = v[1];
		s2 = v[2];
		printf("s1: %s\ns2: %s\nres: %s\n", s1, s2, ft_strjoin(s1, s2));
	}
	return (0);
}*/
