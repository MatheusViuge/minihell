/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:00:17 by jesda-si          #+#    #+#             */
/*   Updated: 2025/06/29 15:51:42 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	atoi_exit(char *str);

bool	ft_exit(char **args, t_data *data)
{
	ft_putendl_fd("exit", 1);
	if (len_args(args) > 1)
	{
		data->exit_code = 2;
		ft_putendl_fd("número de argumentos excessivos", 2);
		return (true);
	}
	if (args)
		data->exit_code = atoi_exit(*args);
	else
		data->exit_code = 0;
	return (false);
}

static int	atoi_exit(char *str)
{
	int	nbr;
	int	i;
	int	neg;

	if (!str)
		return (0);
	i = 0;
	nbr = 0;
	neg = 1;
	if (str[i] == '-')
		neg *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			ft_putstr_fd(str, 2);
			ft_putendl_fd(": requer um argumento númerico", 2);
			return (2);
		}
		nbr = (nbr * 10) + (str[i++] - '0');
	}
	return (nbr * neg);
}
