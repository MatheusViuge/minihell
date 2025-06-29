/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:13:17 by jesda-si          #+#    #+#             */
/*   Updated: 2025/06/28 23:29:10 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	len_args(char **args);

void	cd(char **args, t_env **env)
{
	char	*old_pwd;
	char	*str;
	char	**strs;
	int		nbr;

	nbr = len_args(args);
	if (nbr > 1)
	{
		printf("número excessivo de argumentos\n");
		return ;
	}
	old_pwd = getcwd(NULL, 0);
	nbr = chdir(*args);
	if (nbr == -1)
		return ;
	str = ft_join_args(4, "OLDPWD=", old_pwd, " PWD=", *args);
	if (!str)
		return ;
	strs = ft_split(str, 32);
	free(str);
	if (!strs)
		return ;
	unset(strs, env);
	free(strs[0]);
	free(strs[1]);
	free(strs);
}

static int	len_args(char **args)
{
	int	len;

	len = 0;
	while (args[len])
		len++;
	return (len);
}
