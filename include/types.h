/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 23:21:15 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/14 23:21:18 by jesda-si         ###   ########.fr       */
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
	word,
	pipes,
	red_in,
	red_out,
}	t_type_token;

typedef struct s_token
{
	char			*value;
	t_type_token	type;
	struct s_token	*next;
	struct s_token	*prev;
}	t_token;

#endif
