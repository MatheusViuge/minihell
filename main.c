/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:20:52 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 01:19:10 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_env	*env_list;
	char	*prompt;
	t_token	*tokens;

	(void)ac;
	(void)av;
	env_list = NULL;
	tokens = NULL;
	create_env(env, &env_list);
	while (1)
	{
		prompt = readline("prompt> ");
		if (!prompt)
			continue ;
		add_history(prompt);
		token(prompt, &tokens);
		free(prompt);
		print_tokens(tokens);
		if (size_tokens(tokens) == 1 && !ft_strncmp(tokens->value, "exit", 5))
			break ;
		free_tokens(&tokens);
	}
	free_tokens(&tokens);
	free_env(env_list);
	clear_history();
	return (0);
}
