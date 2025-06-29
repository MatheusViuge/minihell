/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 21:13:17 by jesda-si          #+#    #+#             */
/*   Updated: 2025/06/28 22:12:57 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	len_args(char **args);
static char	*join_variables(char **old_pwd, char *new_pwd);

void	cd(char **args, t_env **env)
{
	char	*old_pwd;
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
		return ; // printar erro
	strs = join_variables(&old_pwd, *args);
	if (!strs)
		return ;
	unset(strs, env);
	free(strs[0]);
	free(strs[1]);
	free(strs);
}

static char	*join_variables(char **old_pwd, char *new_pwd)
{
	char	*tmp;
	char	*str;
	char	*strs;

	tmp = ft_strjoin("OLDPWD=", old_pwd);
	free(*old_pwd);
	if (!tmp)
		return (NULL);
	*old_pwd = ft_strjoin(tmp, " ");
	free(tmp);
	if (!*old_pwd)
		return (NULL);
	tmp = ft_strjoin(*old_pwd, "PWD=");
	free(*old_pwd);
	if (!tmp)
		return (NULL);
	str = ft_strjoin(tmp, new_pwd);
	free(tmp);
	if (!str)
		return (NULL);
	strs = ft_split(str, 32);
	free(str);
	return (strs);
}

static int	len_args(char **args)
{
	int	len;

	len = -1;
	while (args[++len])
		;
	return (len);
}
