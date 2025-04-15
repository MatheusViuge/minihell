/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstadd_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:44:33 by jesda-si          #+#    #+#             */
/*   Updated: 2025/02/04 17:08:25 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dbl_lstadd_back(t_dbl_list **lst, t_dbl_list *new)
{
	t_dbl_list	*p;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	p = ft_dbl_lstlast(*lst);
	p->next = new;
	new->prev = p;
}
