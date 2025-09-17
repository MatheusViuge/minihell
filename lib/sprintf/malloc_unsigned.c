/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_unsigned.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:22:59 by jessica           #+#    #+#             */
/*   Updated: 2025/08/24 19:12:34 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"

char	*malloc_unsigned(va_list *args)
{
	unsigned int	nbr;
	char			*str;
	char			*first;
	char			*last;

	nbr = (unsigned int)va_arg(*args, unsigned int);
	if (nbr <= 2147483647)
	{
		str = ft_itoa(nbr);
		return (str);
	}
	first = ft_itoa(nbr / 1000);
	last = ft_itoa(nbr % 1000);
	if (!first || !last)
		return (NULL);
	str = ft_strjoin(first, last);
	free(first);
	free(last);
	return (str);
}
