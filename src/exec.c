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

char	*exec_command(char **command, t_env *env)
{
	t_token	*tokens;
	char	*str;

	str = NULL;
	tokens = NULL;
	token(*command, &tokens);
	expand_variables(&tokens, env);
	print_tokens(tokens);
	if (size_tokens(tokens) == 1 && !ft_strncmp(tokens->value, "exit", 5))
	{
		free_tokens(&tokens);
		free_env(env);
		exit(EXIT_SUCCESS);
	}
	free_tokens(&tokens);
	str = ft_strdup(*command);
	free(*command);
	return (str);
}
