/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 21:32:05 by mviana-v          #+#    #+#             */
/*   Updated: 2025/09/20 21:44:06 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	handle_pid(t_data *data, int pid)
{
	t_pid	*new_pid;
	t_pid	*current;

	new_pid = (t_pid *)ft_calloc(sizeof(t_pid), 1);
	if (!new_pid)
		exit_error(NULL, NULL, NULL);
	new_pid->pid = pid;
	if (!data->pids)
		data->pids = new_pid;
	else
	{
		current = data->pids;
		while (current->next)
			current = current->next;
		current->next = new_pid;
	}
}

void	pid_cleaner(t_pid *pid)
{
	t_pid	*current;
	t_pid	*next;

	if (!pid)
		return ;
	current = pid;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	pid_wait(t_data *data, t_pid *pid)
{
	t_pid	*current;
	int		status;

	status = 0;
	current = pid;
	while (current)
	{
		if (waitpid(current->pid, &status, 0) == -1
			&& g_sig != SIGINT && g_sig != SIGQUIT)
			perror("waitpid");
		if (WIFEXITED(status))
			data->exit_code = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			data->exit_code = 128 + WTERMSIG(status);
		else if (WIFSTOPPED(status))
			data->exit_code = 128 + WSTOPSIG(status);
		current = current->next;
	}
	pid_cleaner(pid);
	data->pids = NULL;
}
