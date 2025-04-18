/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 12:46:53 by mviana-v          #+#    #+#             */
/*   Updated: 2025/04/18 00:34:59 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_H
# define MINI_H
# include "./lib/libft.h"
# include <stdio.h>

// Structs and typedefs
typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
	struct s_env	*prev;
}	t_env;

// Function prototypes

/*	env functions	*/
void	create_env(char **env, t_env **head);
void	print_env(t_env *head);
void	free_env(t_env *head);

#endif
