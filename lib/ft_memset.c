/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:59:47 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/05 19:49:57 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	void	*s;
	int	len;
	if (c == 3)
	{
		len = ft_strlen(v[1]) + 1;
		s = malloc(sizeof(char) + len);
		ft_strlcpy((char *)s, v[1], len);
		printf("%s\n", (char *)s);
		printf("%s\n", (char *)ft_memset(s, v[2][0], 3));
	}
	return (0);
}*/
