/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:20:02 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:28:00 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + ('a' - 'A'));
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
			printf("%c\n", ft_tolower(v[1][i++]));
	}
	return (0);
}*/
