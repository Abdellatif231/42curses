/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_I.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:27:50 by amaaouni          #+#    #+#             */
/*   Updated: 2024/06/13 16:55:38 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	post_point(const char *str, int i)
{
	double	frac;
	double	div;

	frac = 0.0;
	div = 1.0;
	if (str[i] == '.')
	{
		i++;
		while (str[i] > 47 && str[i] < 58)
		{
			frac = (frac * 10) + (str[i] - 48);
			div *= 10;
			i++;
		}
	}
	return (frac / div);
}

double	ft_atof(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '-' && (str[i + 1] > 47 && str[i + 1] < 58))
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '+' && (str[i + 1] > 47 && str[i + 1] < 58))
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return ((num + post_point(str, i)) * sign);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}

float	map(float num, float o_min, float o_max, t_fractal *f)
{
	return (((num - o_min) * (f->scale.max - f->scale.min) / (o_max - o_min))
		+ f->scale.min);
}
