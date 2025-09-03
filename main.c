/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:20:52 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/03 16:46:28 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	main(int ac, char **av, char **env)
{
	t_data	data;
	bool	loop;

	(void)ac;
	(void)av;
	loop = true;
	data.exit_code = 0;
	data.env = create_env(env);
	while (loop)
		loop = line_comand(&data);
	clear_history();
	free_data(&data);
	return (data.exit_code);
}

bool	line_comand(t_data *data)
{
	char	*prompt;
	bool	res;

	data->tokens = NULL;
	data->ast = NULL;
	data->pids = NULL;
	prompt = readline("mini> ");
	if (!prompt)
		return (false);
	if (ft_strlen(prompt) == 0)
		return (true);
	add_history(prompt);
	res = parser(data, prompt);
	free(prompt);
	if (!res)
		return (false);
	else
		exec_handler(data);
	if (size_tokens(data->tokens) == 1
		&& !ft_strncmp(data->tokens->value, "exit", 5))
		return (false);
	free_ast(&data->ast);
	free_tokens(&data->tokens);
	return (true);
}
