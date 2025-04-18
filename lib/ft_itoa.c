/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:15:03 by mviana-v          #+#    #+#             */
/*   Updated: 2024/10/11 18:08:25 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	int_len(long n)
{
	size_t	i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static void	ft_putnbr(char *str, size_t index, long num, size_t size)
{
	if (num > 9)
		ft_putnbr(str, index + 1, num / 10, size);
	str[size - index] = (num % 10) + '0';
}

char	*ft_itoa(int n)
{
	size_t	len;
	long	i;
	long	num;
	char	*result;

	len = int_len(n);
	num = n;
	if (num >= 0)
	{
		result = (char *)ft_calloc(len + 1, sizeof(char));
		i = 1;
	}
	else
	{
		result = (char *)ft_calloc(len + 2, sizeof(char));
		num *= -1;
		i = 0;
		result[0] = '-';
	}
	if (!result)
		return (NULL);
	ft_putnbr(result, i, num, len);
	return (result);
}
