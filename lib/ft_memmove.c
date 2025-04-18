/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:10:01 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:38:36 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest <= src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (dest);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	if (c == 2)
	{
		void	*d;
		void	*s;
		int	len;

		len = ft_strlen(v[1]) + 1;
		d = malloc(sizeof(char) + len);
		s = malloc(sizeof(char) + len);
		ft_strlcpy(s, v[1], len);
		ft_memmove(d, (const void *)s, len);
		printf("src:  %s\ndest: %s\n", (char *)s, (char *)d);
	}
	return (0);
}*/
