/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_n                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 16:29:08 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:38:10 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_nbr(char const *s, int c)
{
	int	i;
	int	len;

	if (!s || !*s)
		return (-1);
	len = (int)ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (char)c)
			break ;
		i++;
	}
	return (i);
}
