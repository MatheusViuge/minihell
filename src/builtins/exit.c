/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:00:17 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/20 18:58:22 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	atoi_exit(char *str);

void	ft_exit(t_node *ast, t_data *data)
{
	int	exit_code;

	ft_putendl_fd("exit", 1);
	if (len_args(&ast->cmd[1]) > 1)
	{
		data->exit_code = 2;
		ft_putendl_fd("too many arguments", 2);
		return ;
	}
	if (ast && ast->cmd[1])
		exit_code = atoi_exit(ast->cmd[1]);
	else
		exit_code = 0;
	free_data(data);
	exit(exit_code);
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
			ft_putendl_fd(": numeric argument required", 2);
			return (2);
		}
		nbr = (nbr * 10) + (str[i++] - '0');
	}
	return (nbr * neg);
}
