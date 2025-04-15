/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:58:26 by jesda-si          #+#    #+#             */
/*   Updated: 2024/09/29 20:50:18 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = '\0';
		i++;
	}
}

/*int	main(int c, char **v)
{
	void	*s;
	size_t	n;

	if (c > 2)
	{
		n = ft_strlen(v[1]);
		s = malloc(sizeof(char) * (n + 1));
		ft_strlcpy(s, v[1], n + 1);

		write(1, s, n);
		ft_bzero(s, ft_atoi(v[2]));
		write(1, s, n);
	}
	return (0);
}*/
