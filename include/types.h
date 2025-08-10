/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:21:15 by jesda-si          #+#    #+#             */
/*   Updated: 2025/07/23 20:32:12 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

typedef enum e_type_token
{
	WORD,
	PIPE,
	REDIR_IN,
	REDIR_OUT,
	HEREDOC,
	APPEND,
	COMMAND,
	BUILTIN,
}	t_type_token;

typedef struct s_token
{
	char			*value;
	t_type_token	type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

typedef struct s_redir
{
	t_type_token	type;
	char			*name;
	struct s_redir	*next;
}	t_redir;

typedef struct s_node
{
	t_type_token	type;
	char			**cmd;
	t_redir			*redirs;
	int				fd_in;
	int				fd_out;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_pid
{
	int				pid;
	struct s_pid	*next;
}	t_pid;

typedef struct s_data
{
	t_env	*env;
	t_pid	*pids;
	t_token	*tokens;
	t_node	*ast;
	int		exit_code;
}	t_data;

typedef struct s_expand
{
	char	*prev;
	char	*next;
	char	*new;
}	t_expand;

#endif
