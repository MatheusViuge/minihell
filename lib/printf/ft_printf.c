/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:55:07 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/19 13:36:58 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(char c, va_list *args);

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar_fd(str[i], 1);
		else if (str[i] == '%' && str[i + 1] && str[i + 1] == '%')
			ft_putchar_fd(str[i++], 1);
		else if (str[i] == '%')
			count += print_format(str[++i], &args) - 1;
		count++;
		i++;
	}
	va_end(args);
	return (count);
}

static int	print_format(char c, va_list *args)
{
	if (c == 'c')
		return (print_char(args));
	if (c == 's')
		return (print_str(args));
	if (c == 'p')
		return (print_pointer(args));
	if (c == 'd' || c == 'i')
		return (print_nbr(args));
	if (c == 'u')
		return (print_unsigned(args));
	if (c == 'x' || c == 'X')
		return (print_hex(args, c));
	return (0);
}
