/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:33:49 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:37:54 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;
	size_t	j;

	len_dest = ft_strlen(dst);
	if (len_dest > size)
		len_dest = size;
	len_src = ft_strlen(src);
	if (size > 0 && len_dest < (size - 1))
	{
		i = 0;
		j = len_dest;
		while (src[i] && j < (size - 1))
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	return (len_dest + len_src);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	char	*str;
	size_t	n;

	if (c == 4)
	{
		n = ft_strlen(v[1]) + ft_strlen(v[2]);
		str = ft_calloc(n + 1, sizeof(char));
		ft_strlcpy(str, v[1], n + 1);
		printf("len: %d \nres: %zu: %s\n", n, 
		ft_strlcat(str, v[2], ft_atoi(v[3])), dest);
	}
	return (0);
}*/
