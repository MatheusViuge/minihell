/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:53:13 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/18 17:25:29 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int     main(int c, char **v)
{
	char *s;
	int	len;

	if (c == 3)
	{
		len = ft_strlen(v[1]);
		s = malloc(sizeof(char) * len + 1);
		ft_strlcpy(s, v[1], len + 1);

		printf("%s\n", (const char *)ft_memchr(s, v[1][0], len));
	}
	return (0);
}*/
