/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:13:17 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/19 14:25:03 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

//static void	free_strs(char **strs);

void	cd(t_node *ast, t_env **env)
{
	char	*old_pwd;
	char	*str;
	char	**strs;

	(void)env;
	if (len_args(&ast->cmd[1]) > 1)
	{
		printf("too many arguments\n");
		return ;
	}
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return ; // error
	str = ft_join_args(4, "OLDPWD=", old_pwd, " PWD=", ast->cmd[1]);
	free(old_pwd);
	if (!str)
		return ; // error
	strs = ft_split(str, 32);
	free(str);
	if (!strs)
		return ; // error
	if (chdir(ast->cmd[1]) == -1)
	{
		free_split(&strs);
		perror("cd");
		return ; // error
	}
	unset(strs, env);
	free_split(&strs);
}

int	len_args(char **args)
{
	int	len;

	len = 0;
	while (args && args[len])
		len++;
	return (len);
}
