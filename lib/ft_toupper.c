/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:12:39 by jesda-si          #+#    #+#             */
/*   Updated: 2024/09/28 17:03:22 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

/*#include <stdio.h>

int	main(void)
{
	int	i;

	if (c > 1)
	{
		i = 0;
		while (v[1][i])
			printf("%c\n", ft_toupper(v[1][i++]));
	}
	return (0);
}*/
