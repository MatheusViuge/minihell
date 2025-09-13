/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:20:52 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/13 16:36:09 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minishell.h"

int	g_sig;

static void	set_signal_handler(void);
static void	set_exit_code(t_data *data);

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
	if (!prompt)
		return (false);
	if (ft_strlen(prompt) == 0)
		return (true);
	add_history(prompt);
	set_exit_code(data);
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

void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (signum == SIGINT)
	{
		g_sig = info->si_signo;
		rl_replace_line("", 1);
		ft_putchar_fd('\n', 1);
		rl_on_new_line();
		if (info->si_pid != 0)
			rl_redisplay();
	}
	else if (signum == SIGQUIT)
	{
		g_sig = info->si_signo;
		rl_on_new_line();
		rl_redisplay();
	}
}

static void	set_signal_handler(void)
{
	struct sigaction	action;

	action.sa_sigaction = signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGQUIT, &action, NULL);
}

static void	set_exit_code(t_data *data)
{
	if (g_sig == SIGINT)
		data->exit_code = 130;
	else if (g_sig == SIGQUIT)
		data->exit_code = 131;
	g_sig = 0;
}