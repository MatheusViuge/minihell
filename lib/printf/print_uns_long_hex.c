/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_uns_long_hex.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:45:50 by jessica           #+#    #+#             */
/*   Updated: 2024/10/19 19:11:25 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_uns_long_hex(unsigned long nbr, const char *base)
{
	unsigned long	len;
	int				size;

	size = 0;
	len = (unsigned long)ft_strlen(base);
	if (nbr >= len)
	{
		size += print_uns_long_hex(nbr / len, base);
		size += print_uns_long_hex(nbr % len, base);
	}
	else
	{
		ft_putchar_fd(base[nbr], 1);
		size++;
	}
	return (size);
}
