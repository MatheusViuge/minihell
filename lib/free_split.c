/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 19:45:28 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/16 19:48:10 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_split(char ***split)
{
	int	i;

	if (!split || !*split)
		return ;
	i = -1;
	while ((*split)[++i])
		free((*split)[i]);
	free(*split);
	*split = NULL;
}
