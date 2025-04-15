/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesda-si <jesda-si@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 19:32:58 by jesda-si          #+#    #+#             */
/*   Updated: 2024/09/29 19:56:39 by jesda-si         ###   ########.fr       */
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
