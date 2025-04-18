/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:24:32 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:37:51 by mviana-v         ###   ########.fr       */
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
