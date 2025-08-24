/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:53:14 by jesda-si          #+#    #+#             */
/*   Updated: 2025/08/24 19:07:48 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"

char	*malloc_pointer(va_list *args)
{
	unsigned long	p;
	char			*str;
	char			*tmp;

	p = (unsigned long)va_arg(*args, void *);
	if (!p)
		str = ft_strdup("(nil)");
	tmp = malloc_uns_long_hex(p, "0123456789abcdef");
	if (!tmp)
		return (NULL);
	str = ft_strjoin("0x", tmp);
	free(tmp);
	return (str);
}
