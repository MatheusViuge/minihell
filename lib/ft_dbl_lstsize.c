/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:36:05 by jesda-si          #+#    #+#             */
/*   Updated: 2025/02/04 17:57:23 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dbl_lstsize(t_dbl_list *lst)
{
	t_dbl_list	*p;
	int			i;

	i = 0;
	p = lst;
	while (p)
	{
		p = (t_dbl_list *)(*p).next;
		i++;
	}
	return (i);
}
