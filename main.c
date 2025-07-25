/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:20:52 by jesda-si          #+#    #+#             */
/*   Updated: 2025/07/25 16:28:45 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

void	free_data(t_data *data)
{
	if (data->env)
		free_env(data->env);
	if (data->tokens)
		free_tokens(&data->tokens);
	if (data->ast)
		free_ast(&data->ast);
}

int	main(int ac, char **av, char **env)
{
	t_data	data;
	char	*prompt;
	bool	loop;
	bool	parsed;

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
		parsed = parser(&data, prompt);
		free(prompt);
		if (parsed)
			exec_handler(&data);
		if (size_tokens(data.tokens) == 1 && !ft_strncmp(data.tokens->value,
				"exit", 5))
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
