/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 22:04:39 by jesda-si          #+#    #+#             */
/*   Updated: 2025/05/07 22:04:42 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

bool	exec_command(t_data *data, char *command)
{
	char	*str;
	bool	res;

	str = NULL;
	res = token(data, command);
	if (res)
	{
		expand_variables(&data->tokens, data->env);
		print_tokens(data->tokens);
	}
	if (size_tokens(data->tokens) == 1
		&& !ft_strncmp(data->tokens->value, "exit", 5))
	{
		free_tokens(&data->tokens);
		return (false);
	}
	free_tokens(&data->tokens);
	return (true);
}
