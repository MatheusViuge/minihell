/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:20:52 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/20 15:56:14 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	g_sig;

int	main(int ac, char **av, char **env)
{
	t_data	data;
	bool	loop;

	(void)ac;
	(void)av;
	set_signal_handler();
	loop = true;
	data.exit_code = 0;
	data.pids = NULL;
	data.env = create_env(env);
	env_init(&data);
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
	prompt = readline("mini> ");
	set_exit_code(data);
	if (!prompt)
	{
		ft_putstr_fd("exit\n", 1);
		return (false);
	}
	if (ft_strlen(prompt) == 0)
		return (true);
	add_history(prompt);
	res = parser(data, prompt);
	free(prompt);
	if (!res)
		return (false);
	else
		exec_handler(data);
	free_ast(&data->ast);
	free_tokens(&data->tokens);
	return (true);
}
