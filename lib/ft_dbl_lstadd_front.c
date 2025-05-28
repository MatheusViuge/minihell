/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstadd_front.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:46:33 by jesda-si          #+#    #+#             */
/*   Updated: 2025/02/04 16:42:05 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dbl_lstadd_front(t_dbl_list **lst, t_dbl_list *new)
{
	t_dbl_list	*p;

	p = *lst;
	if (!p)
	{
		*lst = new;
		return ;
	}
	new->next = (t_dbl_list *)p;
	p->prev = new;
	*lst = new;
}
