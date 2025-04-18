/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:16:57 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:38:43 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(void const *s1, void const *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if ((p1[i] - p2[i]) != 0)
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	void const	*s1;
	void const	*s2;
	int	len1;
	int	len2;

	if (c == 3)
	{
		len1 = ft_strlen(v[1]) + 1;
		len2 = ft_strlen(v[2]) + 1;
		s1 = malloc(sizeof(char) * len1);
		s2 = malloc(sizeof(char) * len2);
		ft_strlcpy((char *)s1, v[1], len1);
		printf("s1: %s\n", (char *)s1);
		ft_strlcpy((char *)s2, v[2], len2);
		printf("s2: %s\n", (char *)s2);
		printf("res: %d\n", ft_memcmp(s1, s2, 10));
	}
	return (0);
}*/
