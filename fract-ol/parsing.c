/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:33:52 by amaaouni          #+#    #+#             */
/*   Updated: 2024/06/13 19:36:38 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_valid(char *str)
{
	int	i;

	i = 0;
	if (*str == '\0' || (*str == '+' && *(str + 1) == '\0') || (*str == '-'
			&& *(str + 1) == '\0'))
		return (0);
	while (str[i])
	{
		if (i != 0 && str[i] == '.' && ft_isdigit(str[i + 1]))
			i++;
		if (!ft_isdigit(str[i]) && (i != 0 || (str[i] != '+' && str[i] != '-')))
			return (0);
		i++;
	}
	return (1);
}

void	check_arg(int ac, char *av[], t_fractal *data)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_valid(av[i]))
		{
			ft_putstr_fd("Error: Not a valid argument\n", 2);
			exit(1);
		}
		i++;
	}
	if (ac == 2 && ft_atof(av[1]) == 1)
		data->name = "Mandelbrot";
	else if (ac == 4 && ft_atof(av[1]) == 2)
	{
		data->name = "Julia";
		data->av1 = av[2];
		data->av2 = av[3];
	}
	else
	{
		ft_putstr_fd("1 for Mandelbert\n2 for Julia\n", 2);
		exit(1);
	}
}
