/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstswap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:42:19 by jesda-si          #+#    #+#             */
/*   Updated: 2025/02/04 18:03:40 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dbl_lstswap(t_dbl_list **lst)
{
	t_dbl_list	*p;
	t_dbl_list	*tmp;

	p = *lst;
	tmp = p->next;
	p->prev = tmp;
	p->next = tmp->next;
	tmp->prev = NULL;
	tmp->next = p;
	*lst = tmp;
}
