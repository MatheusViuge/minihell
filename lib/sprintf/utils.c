/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:42:04 by jesda-si          #+#    #+#             */
/*   Updated: 2025/09/20 23:53:37 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"

char	**malloc_array_args(const char *str)
{
	int		i;
	int		count;
	char	**array_args;

	array_args = NULL;
	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] != '%')
				count++;
			else
				i++;
		}
		i++;
	}
	array_args = (char **)ft_calloc(count + 1, sizeof(char *));
	return (array_args);
}

char	*malloc_new_str(const char *str, char **array_args)
{
	int		i;
	int		count;
	char	*new_str;

	i = 0;
	count = 0;
	while (str && str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == '%')
				count++;
			i++;
		}
		else
			count++;
		i++;
	}
	i = -1;
	while (array_args && array_args[++i])
		count += ft_strlen(array_args[i]);
	new_str = (char *)ft_calloc(count + 1, sizeof(char));
	return (new_str);
}

void	free_array_args(char ***array_args)
{
	int	i;

	if (!array_args || !*array_args)
		return ;
	i = -1;
	while (*array_args && (*array_args)[++i])
		free((*array_args)[i]);
	free(*array_args);
	*array_args = NULL;
}
