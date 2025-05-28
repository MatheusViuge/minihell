/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:19:59 by jesda-si          #+#    #+#             */
/*   Updated: 2025/02/04 16:54:44 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dbl_lstiter(t_dbl_list *lst, void (*f)(void *))
{
	t_dbl_list	*p;

	p = lst;
	while (p)
	{
		f((*p).content);
		p = (*p).next;
	}
}
