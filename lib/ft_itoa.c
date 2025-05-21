/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:49:01 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:38:50 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calc_len_int(int n);

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	long	nb;
	char	*str;

	len = calc_len_int(n);
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	nb = (long)n;
	if (nb < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		str[0] = '0';
	i = len - 1;
	while (nb > 0)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
	return (str);
}

static int	calc_len_int(int n)
{
	int		c;
	long	nb;

	nb = (long)n;
	c = 0;
	if (nb < 0)
	{
		c++;
		nb *= -1;
	}
	if (nb == 0)
		c++;
	while (nb > 0)
	{
		nb /= 10;
		c++;
	}
	return (c);
}
