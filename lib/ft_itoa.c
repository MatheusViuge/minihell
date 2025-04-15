/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 15:49:01 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/05 19:44:49 by jesda-si         ###   ########.fr       */
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

/*#include <stdio.h>

int	main(int c, char **v)
{
	if (c == 2) 
		printf("%s\n", ft_itoa(ft_atoi(v[1])));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	return (0);
}*/
