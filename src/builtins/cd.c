/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:13:17 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/24 22:48:22 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*create_pwd(char *arg, t_env *env);
static char	**create_variables(char **pwd, char *arg, t_env *env);
static char	*hadle_getcwd_error(char **pwd, t_env *env);

void	cd(char **args, t_env **env)
{
	char	**strs;
	char	*pwd;
	int		ret;

	if (len_args(args) > 1)
	{
		ft_putendl_fd("too many arguments", 2);
		return ;
	}
	strs = create_variables(&pwd, args[0], *env);
	if (access(pwd, F_OK) != 0)
	{
		perror("cd");
		free(pwd);
		free_split(&strs);
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

static char	**create_variables(char **pwd, char *arg, t_env *env)
{
	char	*str;
	char	**strs;
	char	*old_pwd;

	old_pwd = getcwd(NULL, 0);
	if (!old_pwd)
	{
		perror("cd");
		old_pwd = hadle_getcwd_error(pwd, env);
	}
	else
		*pwd = create_pwd(arg, env);
	str = ft_sprintf("OLDPWD=%s PWD=%s", old_pwd, *pwd);
	free(old_pwd);
	if (!str)
		exit_error(NULL, NULL, NULL);
	strs = ft_split(str, 32);
	free(str);
	if (!strs)
	{
		free(*pwd);
		exit_error(NULL, NULL, NULL);
	}
	return (strs);
}

static char	*hadle_getcwd_error(char **pwd, t_env *env)
{
	char	*old_pwd;

	old_pwd = ft_strdup("");
	free(*pwd);
	*pwd = find_value_env("HOME", env);
	if (!old_pwd || !*pwd)
	{
		free(old_pwd);
		exit_error(NULL, NULL, &pwd);
	}
	return (old_pwd);
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
	if (!pwd)
		exit_error(NULL, NULL, NULL);
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
