/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:35:11 by mviana-v          #+#    #+#             */
/*   Updated: 2024/10/14 21:12:31 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*result;

	result = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (result[i] == (unsigned char)c)
			return ((void *)&result[i]);
		i++;
	}
	return (NULL);
}
