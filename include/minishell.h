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

char			*exec_command(char **command, t_env *env);

/*	env functions	*/
void			create_env(char **env, t_env **head);
void			print_env(t_env *head);
void			free_env(t_env *head);

/*  token functions  */
void			token(char *prompt, t_token **tokens);
char			*end_token(char *str);
t_type_token	type_token(char *token);
t_token			*new_token(char *str);
int				size_tokens(t_token *tokens);
t_token			*last_token(t_token *tokens);
void			add_token(t_token **tokens, t_token *new);
t_token			*create_token(char *prompt, char *start, char *end,
					size_t *size);
int				token_quote(char *str, char **end);
char			*token_meta_char(const char *meta_char, char **end);

/*  expanding variables */
void			expand_variables(t_token **tokens, t_env *env);
void			replace_variable(char **value, int *index, t_env *env);
void			token_recreate(char **value, char *variable, int *index,
					t_env *env);
char			*find_key(char *variable, t_env *env);
int				keycmp(char *variable, char **str, t_env env);

/*  para apagar      */
void			print_tokens(t_token *tokens);
void			free_tokens(t_token **tokens);

#endif
