/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:25:04 by mviana-v          #+#    #+#             */
/*   Updated: 2025/04/18 00:26:30 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	t_env	*env_list;
	(void)ac;
	(void)av;
	
	env_list = NULL;
	create_env(env, &env_list);
	print_env(env_list);
	free_env(env_list);
}
