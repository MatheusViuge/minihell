/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:24:32 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/03 19:36:53 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	int	i;

	if (c > 1)
	{
		i = 1;
		while (i++ < c)
			printf("len: %d - str: %s\n", ft_strlen(v[i]), v[i]);
	}
	return (0);
}*/
