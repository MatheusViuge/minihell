/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_lstmap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jessica <jessica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:43:02 by jesda-si          #+#    #+#             */
/*   Updated: 2025/02/04 17:07:39 by jessica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dbl_list	*ft_dbl_lstmap(t_dbl_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_dbl_list	*p;
	t_dbl_list	*new;
	t_dbl_list	*tmp;
	void		*content;

	content = f(lst->content);
	new = ft_dbl_lstnew(content);
	if (!new)
		return (NULL);
	p = lst->next;
	while (p)
	{
		content = f(p->content);
		tmp = ft_dbl_lstnew(content);
		if (!tmp)
		{
			ft_dbl_lstclear(&new, del);
			return (NULL);
		}
		ft_dbl_lstadd_back(&new, tmp);
		p = (t_dbl_list *)(*p).next;
	}
	return (new);
}
