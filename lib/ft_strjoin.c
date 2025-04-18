/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 16:06:07 by mviana-v          #+#    #+#             */
/*   Updated: 2024/09/24 16:59:28 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		index_dest;
	int		index;
	int		counter;
	char	*dest;

	index_dest = 0;
	index = 0;
	counter = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * (counter + 1));
	if (!dest)
		return (NULL);
	while (s1[index] != '\0')
	{
		dest[index_dest] = s1[index];
		index++;
		index_dest++;
	}
	index = 0;
	while (s2[index] != '\0')
	{
		dest[index_dest + index] = s2[index];
		index++;
	}
	dest[index_dest + index] = '\0';
	return (dest);
}
