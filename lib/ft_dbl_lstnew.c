/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:30:01 by jesda-si          #+#    #+#             */
/*   Updated: 2025/02/04 17:56:55 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl_list	*ft_dbl_lstnew(void *content)
{
	t_dbl_list	*lst;

	lst = (t_dbl_list *)ft_calloc(sizeof(t_dbl_list), 1);
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->index = NULL;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}
