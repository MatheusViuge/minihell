/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 17:42:19 by jesda-si          #+#    #+#             */
/*   Updated: 2024/12/02 17:42:21 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list **lst)
{
	t_list	*temp;

	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	(*lst) = temp;
}
