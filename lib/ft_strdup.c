/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:44:18 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/11 13:14:31 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*cpy;

	len = (int)ft_strlen(s) + 1;
	cpy = (char *)ft_calloc(sizeof(char), len);
	if (!cpy)
		return (NULL);
	ft_strlcpy(cpy, s, len);
	return (cpy);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	if (c == 2)
		printf("%s\n", ft_strdup((const char *)v[1]));
	return (0);
}*/
