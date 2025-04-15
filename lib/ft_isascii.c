/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:05:47 by jesda-si          #+#    #+#             */
/*   Updated: 2024/09/25 15:14:30 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*#include <stdio.h>

int	main(int c, char **v)
{
	int	i;

	if (c > 1)
	{
		while (v[1][i])
			printf("%c => %d\n", v[1][i++], ft_isascii(v[1][i++]));
	}
	return (0);
}*/
