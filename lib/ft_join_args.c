/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:40:05 by jesda-si          #+#    #+#             */
/*   Updated: 2025/06/28 23:29:40 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join_args(int length, ...)
{
	char	*tmp;
	char	*str;
	va_list	args;

	va_start(args, length);
	str = NULL;
	while (length-- > 0)
	{
		tmp = va_arg(args, char *);
		str = ft_strjoin(str, tmp);
		if (!str)
			return (NULL);
	}
	va_end(args);
	return (str);
}
