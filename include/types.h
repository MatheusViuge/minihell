/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:21:15 by jesda-si          #+#    #+#             */
/*   Updated: 2025/06/17 16:52:27 by mviana-v         ###   ########.fr       */
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

typedef struct s_args
{
	t_type_token	type;
	char			**args;
	int				fd_in;
	int				fd_out;
	struct s_args	*left;
	struct s_args	*right;
}	t_args;

typedef struct s_data
{
	t_env	*env;
	t_token	*tokens;
	int		exit_code;
}	t_data;

#endif
