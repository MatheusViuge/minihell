bool	echo(char **args)
{
	bool 	flag;
	char 	*tmp;
	char	*str;
	int		i;

	flag = false;
	if (ft_strncmp(args && args[0], "-n", 3))
		flag = true;
	i = (int)flag;
	while (args && args[i])
	{
		tmp = ft_join(str, args[i]);
		if (!tmp)
			return (false);
		free(str);
		str = tmp;
		i++;
	}
	ft_putstr_fd(str, 1);
	if (flag)
		ft_putchar_fd('\n', 1);
	return (true);
}
