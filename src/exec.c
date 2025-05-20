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
	t_token	*node;

	str = NULL;
	res = token(data, command);
	if (res)
	{
		node = data->tokens;
		while (node)
		{
			if (node->type == WORD)
			{
				if (!expand_variable(node, data))
					return (true);
			}
			node = node->next;
		}
		print_tokens(data->tokens);
	}
	// SOMENTE PARA TESTE
	if (size_tokens(data->tokens) == 1
		&& !ft_strncmp(data->tokens->value, "exit", 5))
	{
		free_tokens(&data->tokens);
		return (false);
	}
	free_tokens(&data->tokens);
	return (true);
}
