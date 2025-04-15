/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:16:02 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/03 21:12:21 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char const *big, char const *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	n = ft_strlen(little);
	if (n == 0)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (little[j] && big[i + j] && i + j < len)
		{
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		if (n == j)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	const char	*big;
	const char	*little;

	if (c > 3)
	{
		big = v[1];
		little = v[2];
		printf("big: %s \nlittle: %s \nres: %s\n\n", 
		big, little, ft_strnstr(big, little, ft_atoi(v[3])));
	}
	return (0);
}*/
