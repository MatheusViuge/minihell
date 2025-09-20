/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:13:17 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/20 17:15:49 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*create_pwd(char *arg, t_env *env);
static char	**create_variables(char *pwd);

void	cd(char **args, t_env **env)
{
	char	**strs;
	char	*pwd;
	int		ret;

	if (len_args(args) > 1)
	{
		printf("too many arguments\n");
		return ;
	}
	pwd = create_pwd(args[0], *env);
	strs = create_variables(pwd);
	if (!strs)
	{
		free(pwd);
		return ;
	}
	ret = chdir(pwd);
	if (ret == 0)
		set_env_array_args(env, strs);
	else
		perror("cd");
	free(pwd);
	free_split(&strs);
	return ;
}

static char	**create_variables(char *pwd)
{
	char	*str;
	char	**strs;
	char	*old_pwd;

	if (!pwd)
		return (NULL);
	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
		return (NULL);
	str = ft_sprintf("OLDPWD=%s PWD=%s", old_pwd, pwd);
	free(old_pwd);
	if (!str)
		return (NULL);
	strs = ft_split(str, 32);
	free(str);
	return (strs);
}

static char	*create_pwd(char *arg, t_env *env)
{
	char	*pwd;

	if (!arg || ft_strncmp(arg, "~", 2) == 0)
		pwd = find_value_env("HOME", env);
	else if (ft_strncmp(arg, "-", 2) == 0)
		pwd = find_value_env("OLDPWD", env);
	else
		pwd = ft_strdup(arg);
	return (pwd);
}

int	len_args(char **args)
{
	int	len;

	len = 0;
	while (args && args[len])
		len++;
	return (len);
}
