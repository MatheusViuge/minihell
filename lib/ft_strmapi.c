/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:52:04 by jesda-si          #+#    #+#             */
/*   Updated: 2024/09/29 19:28:16 by jesda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				len;
	char			*str;

	if (!s)
		return (NULL);
	len = (int)ft_strlen(s) + 1;
	str = (char *)ft_calloc(sizeof(char), len);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*char	f(unsigned int i, char c)
{
	if (i >= 0)
		return (ft_toupper(c));
	return (c);
}

int	main(int c, char **v)
{
	char	result;

	if (c == 2)
	{
		result = ft_strmapi(v[1], &f);
		ft_putstr_fd(v[1], 1);
		ft_putchar_fd('\t', 1);
		ft_putendl_fd(result);
	}
	return (0);
}*/
