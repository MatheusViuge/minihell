/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:20:52 by jesda-si          #+#    #+#             */
/*   Updated: 2025/05/20 20:30:23 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	*prompt;
	bool	loop;
	bool	res;

	(void)ac;
	(void)av;
	loop = true;
	data.exit_code = 0;
	data.env = NULL;
	data.tokens = NULL;
	create_env(env, &data.env);
	while (loop)
	{
		prompt = readline("mini> ");
		if (!prompt)
			continue ;
		res = token(&data, prompt, &data.tokens);
		free(prompt);
		if (res)
			print_tokens(data.tokens);
		if (size_tokens(data.tokens) == 1
			&& !ft_strncmp(data.tokens->value, "exit", 5))
			loop = false;
		free_tokens(&data.tokens);
	}
	free_tokens(&data.tokens);
	free_env(data.env);
	return (data.exit_code);
}

bool	return_erro(char *message, int code, t_data *data)
{
	data->exit_code = code;
	ft_putendl_fd(message, 2);
	return (false);
}
