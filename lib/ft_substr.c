/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:23:41 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/05 16:04:10 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	size;

	size = ft_strlen(s);
	if (len > size - start)
		len = size - start;
	len++;
	if (start >= size)
		len = 1;
	str = (char *)ft_calloc(sizeof(char), len);
	if (!str)
		return (NULL);
	if (start < size)
		ft_strlcpy(str, &s[start], len);
	return (str);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	if (c > 3)
		printf("str:%s \nstart: %d \t len: %d\nres: %s\n\n", v[1], 
		ft_atoi(v[2]), ft_atoi(v[3]), 
		ft_substr(v[1], ft_atoi(v[2]), ft_atoi(v[3])));
	return (0);
}*/
