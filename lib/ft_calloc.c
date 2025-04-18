/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:19:06 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:36:42 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb > 0 && ((nmemb * size) / nmemb) != size)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	int		i;
	size_t	nmemb, size, len;
	void	*p;

	if (c > 2)
	{
		nmemb = ft_atoi(v[1]);
		size = ft_atoi(v[2]);
		p = calloc(ft_atoi(v[1]), ft_atoi(v[2]));

		// TESTE
		if (nmemb > 0 && ((nmemb * size) / nmemb) != size)
			len = 0;
		else
			len = nmemb * size;
		i = 0;
		while (i < len)
			printf("%d, ", p[i++]);
	}
	return (0);
}*/
