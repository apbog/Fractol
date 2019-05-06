/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:19:58 by ccollins          #+#    #+#             */
/*   Updated: 2019/05/02 19:20:01 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	color(double p)
{
	if (p == 1)
		return (0x000000);
	else if (p > 0.9)
		return (0x00f9ff);
	else if (p > 0.8)
		return (0x00ff38);
	else if (p > 0.7)
		return (0xfdff00);
	else if (p > 0.6)
		return (0xfd00ff);
	else if (p > 0.5)
		return (0x01df01);
	else if (p > 0.4)
		return (0x8904b1);
	else if (p > 0.3)
		return (0x6a0888);
	else if (p > 0.2)
		return (0x0b610b);
	else if (p > 0.1)
		return (0xc2d6d6);
	else if (p > 0.0)
		return (0xd1e0e0);
	return (0xe0ebeb);
}

static void	julia(t_fractol *fr)
{
	t_point p;

	p.x = -1;
	fr->data->r = calc_r(fr);
	while (++p.x < fr->size)
	{
		p.y = -1;
		while (++p.y < fr->size)
		{
			calc_z0(&p, fr);
			p.k = 0;
			while (p.k < fr->k_max)
			{
				calc_zn(&p, fr);
				if (pow(p.x0, 2) + pow(p.y0, 2) > pow(fr->data->r, 2))
					break ;
				p.k++;
			}
			put_point(fr, p.x, p.y, color(p.k / fr->k_max));
		}
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

static void	mandelbrot(t_fractol *fr)
{
	t_point p;

	p.x = -1;
	while (++p.x < fr->size)
	{
		p.y = -1;
		while (++p.y < fr->size)
		{
			calc_z0(&p, fr);
			p.k = 0;
			p.x0 = 0;
			p.y0 = 0;
			while (p.k < fr->k_max)
			{
				calc_zn(&p, fr);
				if (pow(p.x0, 2) + pow(p.y0, 2) > 4)
					break ;
				p.k++;
			}
			put_point(fr, p.x, p.y, color(p.k / fr->k_max));
		}
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

static void	commands(void *mlx, void *win, int c)
{
	int a;

	a = 15;
	mlx_string_put(mlx, win, 1025, a, c, "Commands:");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "Change type:");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "Julia - J");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "Mandelbrot - M");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "Julia^3 - K");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "Change Julia parameter");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, " - Whitespace");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "&& Mouse Move");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "Zoom - Mouse scroll");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "Move - Arrows");
}

void		plot(t_fractol *fr)
{
	if (fr->type == 0)
		julia(fr);
	if (fr->type == 1)
		mandelbrot(fr);
	if (fr->type == 2)
		julia(fr);
	commands(fr->mlx, fr->win, 0xfdfdfd);
}
