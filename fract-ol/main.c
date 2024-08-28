/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 14:31:07 by amaaouni          #+#    #+#             */
/*   Updated: 2024/06/13 22:36:18 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_fractal *data, void (*f)(t_fractal *))
{
	data->scale.min = -2 * data->zoom;
	data->scale.max = 2 * data->zoom;
	data->x = 0;
	while (data->x < WIDTH)
	{
		data->y = 0;
		while (data->y < HEIGHT)
		{
			f(data);
			data->y++;
		}
		data->x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img.img_ptr, 0, 0);
}

int	main(int ac, char *av[])
{
	t_fractal	data;
	void		(*f)(t_fractal *);

	check_arg(ac, av, &data);
	if (ft_atof(av[1]) == 1)
	{
		data.flag = 1;
		f = mandelbrot;
	}
	else
	{
		data.flag = 2;
		f = julia;
	}
	data.zoom = 1;
	my_init(&data);
	event_handler(&data);
	render(&data, f);
	mlx_loop(&data.mlx);
}
