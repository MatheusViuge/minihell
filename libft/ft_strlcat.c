/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 18:23:58 by mviana-v          #+#    #+#             */
/*   Updated: 2024/10/17 16:59:12 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;
	size_t	index;

	index = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (len_dst >= size)
		return (size + len_src);
	while (src[index] && index < size - len_dst - 1)
	{
		dst[len_dst + index] = src[index];
		index++;
	}
	dst[len_dst + index] = '\0';
	return (len_dst + len_src);
}
