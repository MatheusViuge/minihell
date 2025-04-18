/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:25:04 by mviana-v          #+#    #+#             */
/*   Updated: 2025/04/17 22:45:12 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini.h"
#include <stdio.h>

int	main(int ac, char **av, char **env)
{
	t_env	*env_list;
	(void)ac;
	(void)av;
	
	create_env_list(env, &env_list);
}
