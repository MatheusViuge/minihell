/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:19:06 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/05 19:44:06 by jesda-si         ###   ########.fr       */
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