/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:44:18 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:38:07 by mviana-v         ###   ########.fr       */
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
