/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:00:17 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/01 23:16:58 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	atoi_exit(char *str);

void	ft_exit(t_node *ast, t_data *data)
{
	ft_putendl_fd("exit", 1);
	if (len_args(&ast->cmd[1]) > 1)
	{
		data->exit_code = 2;
		ft_putendl_fd("número de argumentos excessivos", 2);
		return ;
	}
	if (ast->cmd[1])
		data->exit_code = atoi_exit(ast->cmd[1]);
	else
		data->exit_code = 0;
	free_data(data);
	exit(data->exit_code);
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
