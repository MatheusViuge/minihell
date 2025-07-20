/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:09:14 by jesda-si          #+#    #+#             */
/*   Updated: 2025/07/20 15:30:23 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	return_erro(char *msg, char *allocated_msg, int code,
	t_data *data)
{
	bool	ret;

	ret = true;
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (allocated_msg)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(allocated_msg, STDERR_FILENO);
		free(allocated_msg);
	}
	ft_putchar_fd('\n', STDERR_FILENO);
	data->exit_code = code;
	if (data->exit_code == -1)
	{
		ret = false;
		data->exit_code = 1;
	}
	return (ret);
}
