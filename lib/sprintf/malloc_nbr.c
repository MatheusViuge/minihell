/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 16:13:26 by jessica           #+#    #+#             */
/*   Updated: 2025/08/24 18:51:21 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"

char	*malloc_nbr(va_list *args)
{
	int		nbr;
	char	*str;

	nbr = (int)va_arg(*args, int);
	str = ft_itoa(nbr);
	return (str);
}
