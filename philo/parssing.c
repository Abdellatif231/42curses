#include "philo.h"

int	to_int(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '+' && (str[i + 1] > 47 && str[i + 1] < 58))
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	if (str[i])
		return -1;
	return (num);
}

int	check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (to_int(av[i]) < 0)
			return 0;
		i++;
	}
	return 1;
}
