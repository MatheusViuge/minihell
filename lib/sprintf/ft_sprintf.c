/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 17:55:07 by jesda-si          #+#    #+#             */
/*   Updated: 2025/08/24 19:44:05 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sprintf.h"

static char	*switch_format(char c, va_list *args);
static void	malloc_format(const char *str, char **array_args, va_list *args);
static char	*cpy_str_format(char *new_str, const char *str, char **array_args);
static char	*malloc_new_str(const char *str, char **array_args);
static char	**malloc_array_args(const char *str);
static void	free_array_args(char **array_args);

char	*ft_sprintf(const char *str, ...)
{
	va_list		args;
	char		**array_args;
	char		*new_str;

	if (!str)
		return (NULL);
	if (!ft_strchr(str, '%'))
		return (ft_strdup(str));
	array_args = malloc_array_args(str);
	if (!array_args)
		return (NULL);
	va_start(args, str);
	malloc_format(str, array_args, &args);
	va_end(args);
	new_str = malloc_new_str(str, array_args);
	if (!new_str)
	{
		free_array_args(array_args);
		return (NULL);
	}
	cpy_str_format(new_str, str, array_args);
	return (new_str);
}

static char	*cpy_str_format(char *new_str, const char *str, char **array_args)
{
	int	i;
	int	j;
	int	k;
	int	len;

	i = 0;
	j = 0;
	k = 0;
	while (str && str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			if (str[i + 1] == '%')
				new_str[j++] = str[i++];
			else
			{
				len = (int)ft_strlen(array_args[k]);
				ft_strlcpy(&new_str[j], array_args[k], len + 1);
				j += len;
				k++;
				i++;
			}
		}
		else
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
	return (new_str);
}

static void	malloc_format(const char *str, char **array_args, va_list *args)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = ft_strchr(str, '%');
	while (ptr)
	{
		if (ptr + 1 && !ft_strchr("cspdiuxX%", *(ptr + 1)))
		{
			free_array_args(array_args);
			return ;
		}
		array_args[i] = switch_format(*(ptr + 1), args);
		if (!array_args[i])
		{
			free_array_args(array_args);
			return ;
		}
		ptr = ft_strchr(ptr + 1, '%');
		i++;
	}
}

static char	*switch_format(char c, va_list *args)
{
	if (c == 'c')
		return (malloc_char(args));
	if (c == 's')
		return (malloc_str(args));
	if (c == 'p')
		return (malloc_pointer(args));
	if (c == 'd' || c == 'i')
		return (malloc_nbr(args));
	if (c == 'u')
		return (malloc_unsigned(args));
	if (c == 'x' || c == 'X')
		return (malloc_hex(args, c));
	return (NULL);
}

static char	**malloc_array_args(const char *str)
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

static char	*malloc_new_str(const char *str, char **array_args)
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

static void	free_array_args(char **array_args)
{
	int	i;

	i = -1;
	while (array_args && array_args[++i])
		free(array_args[i]);
	free(array_args);
}
