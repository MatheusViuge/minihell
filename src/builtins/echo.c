/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 20:13:13 by jesda-si          #+#    #+#             */
/*   Updated: 2025/08/18 23:03:12 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

bool	echo(char **args)
{
	bool	flag;
	char	*tmp;
	char	*str;
	int		i;

	flag = false;
	if (ft_strncmp(args[0], "-n", 3))
		flag = true;
	i = (int)flag;
	while (args && args[i])
	{
		tmp = ft_strjoin(str, args[i]);
		if (!tmp)
			return (false);
		free(str);
		str = tmp;
		i++;
	}
	ft_putstr_fd(str, 1);
	if (flag)
		ft_putchar_fd('\n', 1);
	return (true);
}
