/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:21:07 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/20 21:20:09 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define _POSIX_C_SOURCE 200809L
# include "../lib/libft.h"
# include "types.h"
# include <dirent.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <termios.h>
# include <dirent.h>
# include <stdbool.h>

bool			line_comand(t_data *data);
void			free_data(t_data *data);
bool			return_erro(char *msg, char *allocated_msg,
					int code, t_data *data);
void			free_redir_list(t_redir *redir);
void			set_signal_handler(void);
void			set_exit_code(t_data *data);
void			env_init(t_data *data);
int				atoi_shlvl(t_env *env);
void			exit_error(t_data *data, char *msg_error, char **path,
					char ***env);

/*	env functions	*/
t_env			*create_env(char **env);
void			env(t_env *head, t_node *ast);
void			free_env(t_env **head);
void			add_env_node(t_env *new_node, t_env **head);
t_env			*new_node(char *str);
char			**convert_env(t_env *env);
void			free_env_array(char **env_array);
int				len_env(t_env *head);
char			*find_value_env(char *variable, t_env *env);
t_env			*find_env(char *variable, t_env *env);
void			set_env_array_args(t_env **head, char **args);

/*  builtins functions */
void			cd(char **args, t_env **env);
void			echo(t_node *ast);
void			export(t_node *ast, t_env **head);
void			unset(char **args, t_env **head);
void			pwd(t_node *ast, t_data *data);
void			ft_exit(t_node *ast, t_data *data);
int				len_args(char **args);
int				define_fd(t_node *ast);

/*	token functions	*/
bool			token(t_data *data, char *prompt);
char			*end_token(char *str);
t_type_token	type_token(char *token);
t_token			*new_token(char *str);
int				size_tokens(t_token *tokens);
void			add_token(t_token **tokens, t_token *new);
t_token			*create_token(char *prompt, char *start, char *end,
					size_t *size);
int				token_quote(char *str, char **end, int *index);
char			*token_meta_char(char *end, int index);
void			free_tokens(t_token **tokens);
bool			token_error(char *prompt, t_data *data);

/*	expanding variables	*/
bool			expand_variable(t_token *token, t_data *data);
void			replace_variable(char **value, int *index, t_data *data);
char			*token_recreate(char *value, char *variable, int *index,
					t_data *data);
void			remove_quotes(char **value, int *index);
void			set_quote(char **token, int *index, int *quote, char c);
t_expand		create_expand(int index, char *str, char *key, t_data *data);
char			*find_value_env(char *variable, t_env *env);
t_env			*find_env(char *variable, t_env *env);
t_expand		create_expand(int index, char *str, char *key, t_data *data);
void			set_quote(char **token, int *index, int *quote, char c);

/* Lexer functions */
bool			lexer(t_data *data);

/*	parser functions	*/
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
void			ast_fd_closer(t_node *ast);

/*	redirects functions	*/
void			handle_redirects(t_data *data, t_node *node);
void			handle_pipes(t_node *node);

/* execution functions */
void			dupper(int fd_in, int fd_out);
void			exec_cleaner(t_data *data, char **path, char ***env);
void			exec(t_data *data, t_node *node, char **path, char **env);
void			exec_handler(t_data *data);
char			**env_transform(t_env *env);
void			free_matrix_env(char ***env);

/* path utilities */
void			path_cleaner(char **path);
void			path_join(char **path, char *cmd);
char			**path_finder(t_env *env, char *cmd);

/* process ID handling */
void			handle_pid(t_data *data, int pid);
void			pid_wait(t_data *data, t_pid *pid);
void			pid_cleaner(t_pid *pid);

/* data cleanup */
void			free_data(t_data *data);

/* builtins */
void			builtin_handler(t_data *data, t_node *node);

/*	para apagar	*/
void			print_tokens(t_token *tokens);
bool			exec_command(t_data *data, char *command);
void			print_ast(t_node *n, int depth);

#endif
