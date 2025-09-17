/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_uns_long_hex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:45:50 by jessica           #+#    #+#             */
/*   Updated: 2025/08/24 19:59:30 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"

char	*malloc_uns_long_hex(unsigned long nbr, const char *base)
{
	unsigned long	len;
	char			*str;
	char			*tmp;
	char			*hex;

	len = (unsigned long)ft_strlen(base);
	str = NULL;
	if (nbr >= len)
	{
		tmp = malloc_uns_long_hex(nbr / len, base);
		if (!tmp)
			return (NULL);
		hex = ft_substr(base, nbr % len, 1);
		str = ft_strjoin(tmp, hex);
		free(tmp);
		free(hex);
		if (!str)
			return (NULL);
	}
	else
		str = ft_substr(base, nbr, 1);
	return (str);
}
