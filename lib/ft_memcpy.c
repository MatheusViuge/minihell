/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 21:16:19 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/03 18:13:55 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	void	*d;
	const void	*s;

	if (c == 3)
	{
		s = malloc(sizeof(char) * (ft_strlen(v[1]) + 1));
		ft_strlcpy((char *)s, v[1], ft_strlen(v[1]) + 1);
		printf("src: %s\n", s);
		printf("dest: %s\n", (char *)ft_memcpy(d, s, ft_atoi(v[2])));
	}
	return (0);
}*/
