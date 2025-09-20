/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 16:05:37 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/19 16:09:28 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	putstr_on_new_line(char *str);
static void	signal_handler(int signum, siginfo_t *info, void *ucontext);

void	set_signal_handler(void)
{
	struct sigaction	action;

	action.sa_sigaction = signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	sigaction(SIGINT, &action, NULL);
	sigaction(SIGQUIT, &action, NULL);
}

void	set_exit_code(t_data *data)
{
	if (g_sig == SIGINT)
		data->exit_code = 130;
	else if (g_sig == SIGQUIT)
		data->exit_code = 131;
	g_sig = 0;
}

static void	signal_handler(int signum, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (signum == SIGINT)
	{
		g_sig = info->si_signo;
		rl_replace_line("", 1);
		putstr_on_new_line("\n");
		if (info->si_pid != 0)
			rl_redisplay();
	}
	else if (signum == SIGQUIT)
	{
		g_sig = info->si_signo;
		if (info->si_pid == 0)
			putstr_on_new_line("Quit (core dumped)\n");
		else
		{
			rl_replace_line("  ", 1);
			rl_redisplay();
			rl_replace_line("", 1);
			rl_redisplay();
			rl_on_new_line();
			rl_redisplay();
		}
	}
}

static void	putstr_on_new_line(char *str)
{
	ft_putstr_fd(str, 1);
	rl_on_new_line();
}
