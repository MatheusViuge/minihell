/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:40:05 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:37:59 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size_s1;
	int		size_s2;
	char	*str;

	size_s1 = (int)ft_strlen(s1);
	size_s2 = (int)ft_strlen(s2);
	str = (char *)ft_calloc(sizeof (char), (size_s1 + size_s2 + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, size_s1 + 1);
	ft_strlcat(str, s2, size_s1 + size_s2 + 1);
	return (str);
}
