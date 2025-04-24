/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:21:07 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/14 23:21:09 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/resource.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <dirent.h>
# include "../lib/libft.h"
# include "types.h"

/*	env functions	*/
void	create_env(char **env, t_env **head);
void	print_env(t_env *head);
void	free_env(t_env *head);

/*  token functions  */
void	token(char *prompt);

#endif
