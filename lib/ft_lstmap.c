/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 17:43:02 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/11 13:12:10 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p;
	t_list	*new;
	t_list	*tmp;
	void	*content;

	content = f(lst->content);
	new = ft_lstnew(content);
	if (!new)
		return (NULL);
	p = lst->next;
	while (p)
	{
		content = f(p->content);
		tmp = ft_lstnew(content);
		if (!tmp)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, tmp);
		p = (t_list *)(*p).next;
	}
	return (new);
}
