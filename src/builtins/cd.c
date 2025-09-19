/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:13:17 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/19 16:54:51 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cd(t_node *ast, t_env **env)
{
	char	*old_pwd;
	char	*str;
	char	**strs;
	char	*pwd;

	(void)env;
	if (len_args(&ast->cmd[1]) > 1)
	{
		printf("too many arguments\n");
		return ;
	}
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return ;
	if (ast->cmd[1] && ft_strncmp(ast->cmd[1], "~", 2) != 0)
		pwd = ft_strdup(ast->cmd[1]);
	else if (!ast->cmd[1] || ft_strncmp(ast->cmd[1], "~", 2) == 0)
		pwd = find_value_env("HOME", *env);
	str = ft_join_args(4, "OLDPWD=", old_pwd, " PWD=", pwd);
	free(old_pwd);
	if (!str)
		return ; // error
	strs = ft_split(str, 32);
	free(str);
	if (!strs)
		return ; // error
	if (chdir(pwd) == -1)
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
