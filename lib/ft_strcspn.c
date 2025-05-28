/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:18:50 by jesda-si          #+#    #+#             */
/*   Updated: 2024/11/27 20:26:09 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t	i;

	i = -1;
	while (s[++i])
	{
		if (ft_strchr(reject, s[i]))
			break ;
	}
	return (i);
}
// "abc" "a" => 0 -> "a"
// "mno" "o" => 2 -> "o"
