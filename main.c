/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:20:52 by jesda-si          #+#    #+#             */
/*   Updated: 2025/07/07 19:19:30 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	*prompt;
	bool	loop;

	(void)ac;
	(void)av;
	loop = true;
	data.exit_code = 0;
	data.env = NULL;
	create_env(env, &data.env);
	while (loop)
	{
		data.tokens = NULL;
		data.ast = NULL;
		prompt = readline("mini> ");
		if (!prompt)
			continue ;
		add_history(prompt);
		parser(&data, prompt);
		free(prompt);
		if (size_tokens(data.tokens) == 1
			&& !ft_strncmp(data.tokens->value, "exit", 5))
			loop = false;
		free_ast(&data.ast);
		free_tokens(&data.tokens);
	}
	clear_history();
	free_data(&data);
	return (data.exit_code);
}

bool	return_erro(char *message, int code, t_data *data)
{
	data->exit_code = code;
	ft_putendl_fd(message, 2);
	return (false);
}
