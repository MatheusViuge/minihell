/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:13:17 by jesda-si          #+#    #+#             */
/*   Updated: 2025/08/28 19:41:41 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//static void	free_strs(char **strs);

void	cd(char **args, t_env **env)
{
	char	*old_pwd;
	char	*str;
	char	**strs;
	(void)env;
	if (len_args(args) > 1)
	{
		printf("número excessivo de argumentos\n");
		return ;
	}
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return ; // error
	if (chdir(*args) == -1)
		return ; // error
	str = ft_join_args(4, "OLDPWD=", old_pwd, " PWD=", *args);
	if (!str)
		return ; // error
	strs = ft_split(str, 32);
	free(str);
	if (!strs)
		return ; // error
	//unset(strs, env);
	//free_strs(strs);
}

/* static void	free_strs(char **strs)
{
	free(strs[0]);
	free(strs[1]);
	free(strs);
}
 */
int	len_args(char **args)
{
	int	len;

	len = 0;
	while (args && args[len])
		len++;
	return (len);
}
