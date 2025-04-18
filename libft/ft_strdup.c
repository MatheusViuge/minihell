/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:50:15 by mviana-v          #+#    #+#             */
/*   Updated: 2024/10/11 18:49:54 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char		*dest;
	size_t		index;

	index = 0;
	while (s[index] != '\0')
		index++;
	dest = (char *)ft_calloc(index + 1, sizeof(char));
	if (!dest)
		return (NULL);
	index = 0;
	while (s[index] != '\0')
	{
		dest[index] = s[index];
		index++;
	}
	return (dest);
}
