/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:20:52 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/20 21:53:13 by jesda-si         ###   ########.fr       */
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
	exit_error(&data, NULL, NULL);
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
		return (true);
	else
		exec_handler(data);
	free_ast(&data->ast);
	free_tokens(&data->tokens);
	return (true);
}

void	exit_error(t_data *data, t_env **env, char ***env_array)
{
	int				exit_code;
	static t_data	*static_data = NULL;

	if (data)
	{
		static_data = data;
		return ;
	}
	exit_code = 1;
	if (static_data->exit_code)
		exit_code = static_data->exit_code;
	ft_putendl_fd("Error: malloc failed", 2);
	free_array_args(env_array);
	free(env);
	free_data(static_data);
	exit(exit_code);
}
