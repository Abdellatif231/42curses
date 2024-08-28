/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 01:43:38 by amaaouni          #+#    #+#             */
/*   Updated: 2024/06/13 22:40:03 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 1000
# define HEIGHT 1000

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_scale
{
	float	min;
	float	max;
}			t_scale;

typedef struct s_fractal
{
	void	*mlx;
	void	*mlx_win;
	char	*name;
	char	*av1;
	char	*av2;
	float	x;
	float	y;
	float	a;
	float	b;
	float	zoom;
	int		color;
	int		max_itr;
	int		flag;
	t_img	img;
	t_scale	scale;
}			t_fractal;

typedef struct s_cpx
{
	float	x;
	float	y;
}			t_cpx;

void		my_init(t_fractal *data);
void		mandelbrot(t_fractal *data);
double		ft_atof(const char *str);
void		ft_putstr_fd(char *s, int fd);
void		julia(t_fractal *data);
void		check_arg(int ac, char *av[], t_fractal *data);
float		map(float num, float o_min, float o_max, t_fractal *f);
int			handle_key(int keycode, t_fractal *data);
int			handle_close(t_fractal *data);
int			handel_mouse(int button, int x, int y, t_fractal *data);
void		event_handler(t_fractal *data);
void		render(t_fractal *data, void (*f)(t_fractal *));

#endif
