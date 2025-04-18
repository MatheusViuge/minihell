/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:25:31 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:37:17 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return ((int)ft_strlen(src));
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	char	*str;
	size_t	len;

	if (c > 1)
	{
		len = ft_strlen(v[1]) + 1;
		str = calloc(len, sizeof(char));
		printf("len: %d \nres: %zu \nstr: %s\n", len, 
		ft_strlcpy(str, v[1], len), copy);
	}
}*/
