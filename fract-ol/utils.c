/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:29:52 by amaaouni          #+#    #+#             */
/*   Updated: 2024/06/13 22:15:05 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_init(t_fractal *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(1);
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGHT, data->name);
	if (!data->mlx_win)
		exit(2);
	data->img.img_ptr = mlx_new_image(&data->mlx, WIDTH, HEIGHT);
	if (!data->img.img_ptr)
		exit(3);
	data->img.pixels_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bpp,
			&data->img.line_len,
			&data->img.endian);
}

void	my_pixel_put(int x, int y, int color, t_fractal *data)
{
	char	*dst;

	dst = data->img.pixels_ptr + ((y * data->img.line_len) + x * (data->img.bpp
				/ 8));
	*(unsigned int *)dst = color;
}

void	data_init(int flag, t_cpx *z, t_cpx *c, t_fractal *data)
{
	data->max_itr = 200;
	data->color = 0xffffff;
	if (flag == 1)
	{
		z->x = 0;
		z->y = 0;
		c->x = map(data->x, 0, WIDTH, data);
		c->y = map(data->y, 0, HEIGHT, data);
	}
	else if (flag == 2)
	{
		c->x = ft_atof(data->av1);
		c->y = ft_atof(data->av2);
		z->x = map(data->x, 0, WIDTH, data);
		z->y = map(data->y, 0, HEIGHT, data);
	}
}

void	mandelbrot(t_fractal *data)
{
	t_cpx	z;
	t_cpx	c;
	int		i;
	float	tmp;

	data_init(1, &z, &c, data);
	i = 0;
	while (i < data->max_itr)
	{
		tmp = ((z.x * z.x) - (z.y * z.y)) + c.x;
		z.y = (2 * z.x * z.y) + c.y;
		z.x = tmp;
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			data->color = i * 16;
			my_pixel_put(data->x, data->y, data->color, data);
			return ;
		}
		i++;
	}
	my_pixel_put(data->x, data->y, 0xffffff, data);
}

void	julia(t_fractal *data)
{
	t_cpx	z;
	t_cpx	c;
	int		i;
	float	tmp;

	data_init(2, &z, &c, data);
	i = 0;
	while (i < data->max_itr)
	{
		tmp = ((z.x * z.x) - (z.y * z.y)) + c.x;
		z.y = (2 * z.x * z.y) + c.y;
		z.x = tmp;
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			data->color = i * 16;
			my_pixel_put(data->x, data->y, data->color, data);
			return ;
		}
		i++;
	}
	my_pixel_put(data->x, data->y, 0xffffff, data);
}
