/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:58:56 by jesda-si          #+#    #+#             */
/*   Updated: 2025/06/29 13:53:54 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	pwd(t_env *head)
{
	t_env	*node;

	node = find_env("PWD", head);
	if (!node)
		return ;
	ft_putendl_fd(node->value, 1);
}
