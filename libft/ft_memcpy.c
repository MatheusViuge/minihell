/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:47:58 by mviana-v          #+#    #+#             */
/*   Updated: 2024/09/30 15:03:11 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	index;
	char	*temp_dest;
	char	*temp_src;

	index = 0;
	temp_dest = dest;
	temp_src = (char *)src;
	while (index < n)
	{
		temp_dest[index] = temp_src[index];
		index++;
	}
	return (dest);
}
