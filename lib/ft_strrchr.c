/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:00:02 by mviana-v          #+#    #+#             */
/*   Updated: 2024/10/11 22:16:02 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	if (!ft_isascii(c))
		return ((char *)s);
	index = ft_strlen(s);
	while (index >= 0)
	{
		if (s[index] == c)
			return ((char *)&s[index]);
		index--;
	}
	return (0);
}
