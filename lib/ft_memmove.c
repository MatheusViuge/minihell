/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:13:41 by mviana-v          #+#    #+#             */
/*   Updated: 2024/10/11 19:01:32 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	index;

	if (dest <= src)
	{
		index = 0;
		while (index < n)
		{
			((char *)dest)[index] = ((unsigned char *)src)[index];
			index++;
		}
	}
	else
	{
		index = n;
		while (index > 0)
		{
			((char *)dest)[index - 1] = ((unsigned char *)src)[index - 1];
			index--;
		}
	}
	return (dest);
}
