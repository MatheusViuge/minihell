/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:20:02 by jesda-si          #+#    #+#             */
/*   Updated: 2024/09/28 17:03:52 by jesda-si         ###   ########.fr       */
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
