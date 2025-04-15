/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:13:26 by jessica           #+#    #+#             */
/*   Updated: 2024/10/19 18:50:12 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(va_list *args)
{
	int		nbr;
	char	*str;

	nbr = (int)va_arg(*args, int);
	str = ft_itoa(nbr);
	ft_putstr_fd(str, 1);
	nbr = (int)ft_strlen(str);
	free(str);
	return (nbr);
}
