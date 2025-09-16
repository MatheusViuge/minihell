/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnrchr_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 20:21:55 by jesda-si          #+#    #+#             */
/*   Updated: 2025/08/10 01:26:45 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnrchr_nbr(char const *s, int c, int end)
{
	int	i;

	i = (int)ft_strlen(s);
	if (i > end)
		i = end;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return (i);
		i--;
	}
	return (i);
}
