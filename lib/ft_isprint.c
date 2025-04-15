/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 18:58:38 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/03 19:38:13 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
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
			printf("%c => %d\n", v[1][i++], ft_isprint(v[1][i++]));
	}
	return (0);
}*/
