/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mviana-v <mviana-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:32:58 by jesda-si          #+#    #+#             */
/*   Updated: 2025/04/18 00:29:52 by mviana-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*void	f(unsigned int i, char *s)
{
	if (i >= 0)
		ft_putchar_fd(*s, 1);
}

int	main(int c, char **v)
{
	char	*str;

	if (c == 2)
	{
		str = v[1];
		ft_striteri(str, &f);
		ft_putendl(str, 1);
	}
}*/
