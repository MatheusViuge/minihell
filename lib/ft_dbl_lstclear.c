/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstclear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 18:08:05 by jesda-si          #+#    #+#             */
/*   Updated: 2025/02/04 16:46:49 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dbl_lstclear(t_dbl_list **lst, void (*del)(void *))
{
	t_dbl_list	*p;
	t_dbl_list	*next;

	p = *lst;
	while (p)
	{
		next = (t_dbl_list *)((*p).next);
		ft_dbl_lstdelone(p, del);
		p = next;
	}
	*lst = NULL;
}
