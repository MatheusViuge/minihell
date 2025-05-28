/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstlast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 15:35:06 by jesda-si          #+#    #+#             */
/*   Updated: 2025/02/04 16:55:55 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl_list	*ft_dbl_lstlast(t_dbl_list *lst)
{
	t_dbl_list	*p;

	p = lst;
	if (!p)
		return (NULL);
	while (p->next)
		p = (t_dbl_list *)p->next;
	return (p);
}
