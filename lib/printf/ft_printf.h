/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:58:43 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/19 11:43:14 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft.h"

int	ft_printf(const char *str, ...);
int	print_char(va_list *args);
int	print_str(va_list *args);
int	print_pointer(va_list *args);
int	print_nbr(va_list *args);
int	print_unsigned(va_list *args);
int	print_hex(va_list *args, char c);
int	print_uns_long_hex(unsigned long p, const char *base);

#endif
