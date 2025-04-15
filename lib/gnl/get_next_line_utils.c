/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 20:08:16 by jesda-si          #+#    #+#             */
/*   Updated: 2024/11/08 20:08:36 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_linelen(char *str, int line)
{
	size_t	i;

	i = 0;
	if (!str || !(*str))
		return (0);
	while (str[i])
	{
		if (str[i++] == '\n' && line)
			return (i);
	}
	return (i);
}

char	*ft_strncpy(char *dest, char *src, ssize_t size)
{
	ssize_t	i;

	if (!dest || !src || size == 0)
		return (NULL);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_subline(char *s, int line)
{
	char	*str;
	size_t	len;

	len = 1;
	if (line)
		len += ft_linelen(s, 1);
	else
		len += ft_linelen(s, 0);
	if (len == 1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_strncpy(str, s, len);
	return (str);
}

char	*ft_join_buffer(char *buffer, char *read)
{
	size_t	i;
	size_t	len;
	char	*str;

	len = 1;
	len += ft_linelen(buffer, 0);
	len += ft_linelen(read, 0);
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
	{
		buffer = free_str(buffer);
		read = free_str(read);
		return (NULL);
	}
	str[0] = '\0';
	ft_strncpy(str, buffer, len);
	i = ft_linelen(str, 0);
	if (i < len)
		ft_strncpy(&str[i], read, len);
	buffer = free_str(buffer);
	read = free_str(read);
	i = ft_linelen(str, 0);
	if (i == 0)
		return (free_str(str));
	return (str);
}
