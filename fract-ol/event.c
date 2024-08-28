/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 22:11:01 by amaaouni          #+#    #+#             */
/*   Updated: 2024/06/13 22:35:26 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_key(int keycode, t_fractal *data)
{
	if (keycode == 53)
	{
		mlx_destroy_image(data->mlx, data->img.img_ptr);
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	return (0);
}

int	handle_close(t_fractal *data)
{
	mlx_destroy_image(data->mlx, data->img.img_ptr);
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
	return (0);
}

void	event_handler(t_fractal *data)
{
	mlx_hook(data->mlx_win, 2, 0, handle_key, data);
	mlx_hook(data->mlx_win, 17, 0, handle_close, data);
	mlx_hook(data->mlx_win, 4, 0, handel_mouse, data);
}

int	handel_mouse(int button, int x, int y, t_fractal *data)
{
	static float	var = 1;

	(void)x;
	(void)y;
	if (button == 4)
		var *= 0.9;
	else if (button == 5)
		var *= 1.1;
	data->zoom = var;
	if (data->flag == 1)
		render(data, mandelbrot);
	else if (data->flag == 2)
		render(data, julia);
	return (0);
}
