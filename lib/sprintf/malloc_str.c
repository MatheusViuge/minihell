/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 19:49:37 by jesda-si          #+#    #+#             */
/*   Updated: 2025/08/24 18:51:35 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"

char	*malloc_str(va_list *args)
{
	char	*str;

	str = va_arg(*args, char *);
	if (!str)
		return (ft_strdup("(null)"));
	return (ft_strdup(str));
}
