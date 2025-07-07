/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:21:15 by jesda-si          #+#    #+#             */
/*   Updated: 2025/06/28 18:48:21 by jesda-si         ###   ########.fr       */
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
	struct s_redir	*redirs;
	int				fd_in;
	int				fd_out;
	struct s_node	*left;
	struct s_node	*right;
}	t_node;

typedef struct s_data
{
	t_env	*env;
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
