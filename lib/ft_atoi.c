/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 20:06:02 by mviana-v          #+#    #+#             */
/*   Updated: 2024/10/02 19:24:04 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *nptr)
{
	long	num;
	int		neg;
	int		index;

	num = 0;
	neg = 1;
	index = 0;
	while (ft_isspace(nptr[index]))
		index++;
	if (nptr[index] == '-')
	{
		neg *= -1;
		index++;
	}
	else if (nptr[index] == '+')
		index++;
	while (ft_isdigit(nptr[index]))
	{
		num = num * 10 + (nptr[index] - '0');
		index++;
	}
	return (num * neg);
}
