/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:21:07 by jesda-si          #+#    #+#             */
/*   Updated: 2025/06/19 20:06:55 by jesda-si         ###   ########.fr       */
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
# include <stdbool.h>
# include <sys/types.h>
# include <sys/resource.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <dirent.h>
# include <stdbool.h>
# include "../lib/libft.h"
# include "types.h"

/*	env functions	*/
void			create_env(char **env, t_env **head);
void			print_env(t_env *head);
void			free_env(t_env *head);

/*  token functions  */
bool			token(t_data *data, char *prompt);
char			*end_token(char *str);
t_type_token	type_token(char *token);
t_token			*new_token(char *str);
int				size_tokens(t_token *tokens);
t_token			*last_token(t_token *tokens);
void			add_token(t_token **tokens, t_token *new);
t_token			*create_token(char *prompt, char *start, char *end,
					size_t *size);
int				token_quote(char *str, char **end);
char			*token_meta_char(char *end);
void			free_tokens(t_token **tokens);

/*  expanding variables */
bool			expand_variable(t_token *token, t_data *data);
char			*replace_variable(char *value, int *index, t_data *data);
char			*token_recreate(char *value, char *variable, int *index,
					t_data *data);
char			*find_key(char *variable, t_env *env);
int				keycmp(char *variable, t_env env, char **str);

/* Lexer functions */
bool			lexer(t_data *data);

/*  para apagar      */
void			print_tokens(t_token *tokens);

bool			return_erro(char *message, int code, t_data *data);
bool			exec_command(t_data *data, char *command);

#endif
