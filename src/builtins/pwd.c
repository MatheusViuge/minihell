/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 20:58:56 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/04 20:30:06 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	pwd(t_data *data)
{
	char	*cwd;

	(void)data;
	cwd = getcwd(NULL, 0);
	printf("%s\n", cwd);
	free(cwd);
	data->exit_code = 0;
}
