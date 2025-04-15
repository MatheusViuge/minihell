/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:57:44 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/03 19:47:51 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char const *s1, char const *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (str1[i] || str2[i]))
	{
		if ((str1[i] - str2[i]) != 0)
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int	main(int c, char **v)

{
	if (c > 3)
		printf("%s \n%s \n%d\n\n", v[1], v[2], 
		ft_strncmp(v[1], v[2], ft_atoi(v[3])));
	return (0);
}*/
