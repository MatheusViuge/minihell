/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:22:59 by jessica           #+#    #+#             */
/*   Updated: 2024/10/19 19:43:06 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_unsigned(va_list *args)
{
	unsigned int	nbr;
	int				size;
	char			*str;

	size = 0;
	nbr = (unsigned int)va_arg(*args, unsigned int);
	if (nbr <= 2147483647)
	{
		str = ft_itoa(nbr);
		ft_putstr_fd(str, 1);
		size += ft_strlen(str);
		free(str);
	}
	else
	{
		str = ft_itoa(nbr / 1000);
		ft_putstr_fd(str, 1);
		size += ft_strlen(str);
		free(str);
		str = ft_itoa(nbr % 1000);
		ft_putstr_fd(str, 1);
		size += ft_strlen(str);
		free(str);
	}
	return (size);
}
