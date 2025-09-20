/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:40:05 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/13 21:43:12 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_join_args(int length, ...)
{
	char	*tmp;
	char	*arg;
	char	*str;
	va_list	args;

	va_start(args, length);
	str = NULL;
	while (length-- > 0)
	{
		arg = va_arg(args, char *);
		tmp = str;
		str = ft_strjoin(tmp, arg);
		free(tmp);
		if (!str)
			return (NULL);
	}
	va_end(args);
	return (str);
}
