/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 17:30:01 by jesda-si          #+#    #+#             */
/*   Updated: 2024/10/11 13:04:35 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = (t_list *)ft_calloc(sizeof(t_list), 1);
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}

/*int	main(int argc, char **argv)
{
	t_list	*lst;

	if (argc > 1)
	{
		lst = ft_lstnew(argv[1]);
		ft_putstr_fd(lst->content, 1);
	}
	return (0);
}*/
