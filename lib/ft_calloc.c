/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:13:22 by mviana-v          #+#    #+#             */
/*   Updated: 2024/10/11 22:43:36 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*any;

	if (nmemb <= 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if ((nmemb * size) / size != nmemb)
		return (NULL);
	any = malloc(nmemb * size);
	if (!any)
		return (NULL);
	ft_bzero(any, nmemb * size);
	return (any);
}
