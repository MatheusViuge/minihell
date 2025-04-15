/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 22:10:01 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/11 13:38:58 by jesda-si         ###   ########.fr       */
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
