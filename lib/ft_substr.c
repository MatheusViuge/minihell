/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:23:41 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:37:23 by mviana-v         ###   ########.fr       */
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
