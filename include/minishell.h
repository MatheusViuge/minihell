/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:21:07 by jesda-si          #+#    #+#             */
/*   Updated: 2025/07/07 16:00:25 by jesda-si         ###   ########.fr       */
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
void			env(t_env *head);
void			free_env(t_env **head);
void			add_env_node(t_env *new_node, t_env **head);
t_env			*new_node(char *str);

/*  builtins functions */
bool			export(char **args, t_env **head);
bool			unset(char **args, t_env **head);
void			pwd(t_env *head);
bool			ft_exit(char **args, t_data *data);
int				len_args(char **args);

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

/*  expanding variables funcrions */
bool			expand_variable(t_token *token, t_data *data);
char			*replace_variable(char *value, int *index, t_data *data);
char			*token_recreate(char *value, char *variable, int *index,
					t_data *data);
char			*find_value_env(char *variable, t_env *env);
t_env			*find_env(char *variable, t_env *env);

/* Lexer functions */
bool			lexer(t_data *data);

/*  parser functions */
bool			parser(t_data *data, char *input);
bool			is_redir(t_token *token);
void			free_ast(t_node **ast);
void			ast_builder(t_data *data);
char			**fill_cmd(t_token *token, int number);
t_node			*create_node(int number, t_token *token, int redir_amount);
void			get_redirs(t_redir **head, t_token *token, int redir_amount);
void			handle_pipe_node(t_data *data, t_token *token);
void			handle_command_node(t_data *data, t_token **token);
void			link_pipe_node(t_data *data, t_node *node);
void			link_node(t_data *data, t_node *node);
bool			ast_error_handler(t_node **ast, t_data *data, char *error_msg);
int				next_type_token(t_token *token, int count);
t_type_token	get_node_type(char *cmd);
t_redir			*new_redir(t_token *token);

/*  para apagar      */
void			print_tokens(t_token *tokens);
bool			exec_command(t_data *data, char *command);
bool			return_erro(char *message, int code, t_data *data);
void			print_ast(t_node *n, int depth);

#endif
