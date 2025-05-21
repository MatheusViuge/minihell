/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 19:16:02 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:37:38 by mviana-v         ###   ########.fr       */
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
