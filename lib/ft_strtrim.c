/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 17:10:14 by mviana-v          #+#    #+#             */
/*   Updated: 2024/10/14 21:19:48 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	to_find(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	len;
	size_t	s1_len;

	start = 0;
	s1_len = ft_strlen(s1);
	end = s1_len - 1;
	while (to_find(set, s1[start]))
		start++;
	while (to_find(set, s1[end]))
		end--;
	len = end - (start) + 1;
	if (len <= 0 || start >= s1_len || s1_len == 0)
		return (ft_strdup(""));
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memmove(str, s1 + start, len);
	return (str);
}
