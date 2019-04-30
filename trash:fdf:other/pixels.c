/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:48:41 by ccollins          #+#    #+#             */
/*   Updated: 2019/04/25 16:48:46 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			put_point(t_fdf *fdf, int x, int y, int color)
{
	int *array;

	array = (int *)(fdf->data_addr);
	if (x > fdf->map->menu_width && x < fdf->map->max_width && y > 0 &&
		y < fdf->map->max_height)
		array[x + y * fdf->size_line / 4] = color;
}

static int		color(double now, double max, t_colors colors)
{
	if (max == 0)
		return (colors.l);
	if (now / max == 1)
		return (colors.a);
	else if (now / max > 0.9)
		return (colors.b);
	else if (now / max > 0.8)
		return (colors.c);
	else if (now / max > 0.7)
		return (colors.d);
	else if (now / max > 0.6)
		return (colors.e);
	else if (now / max > 0.5)
		return (colors.f);
	else if (now / max > 0.4)
		return (colors.g);
	else if (now / max > 0.3)
		return (colors.h);
	else if (now / max > 0.2)
		return (colors.i);
	else if (now / max > 0.1)
		return (colors.j);
	else if (now / max > 0.0)
		return (colors.k);
	return (colors.l);
}

static int		color2(int from, int to, double p)
{
	int r;
	int g;
	int b;

	if (from == to)
		return (from);
	r = (from / 65536) * (1 - p) + (to / 65536) * p;
	g = ((from % 65536) / 256) * (1 - p) + ((to % 65536) / 256) * p;
	b = (from % 256) * (1 - p) + (to % 256) * p;
	return (r * 65536 + g * 256 + b);
}

static double	dst(t_object obj)
{
	return (sqrt(pow((obj.xn - obj.x0), 2) + pow((obj.yn - obj.y0), 2)) /
			sqrt(pow((obj.x1 - obj.x0), 2) + pow((obj.y1 - obj.y0), 2)));
}

void			create_point_from_obj(t_fdf *fdf, t_object obj)
{
	if (fdf->map->color_on == 1)
		put_point(fdf, (int)nearbyint(obj.xn), (int)nearbyint(obj.yn),
				color(obj.h0 + dst(obj) * (obj.h1 - obj.h0),
				(fdf->map->z_max - fdf->map->z_min), *fdf->colors));
	else
		put_point(fdf, (int)nearbyint(obj.xn), (int)nearbyint(obj.yn),
				color2(obj.color0, obj.color1, dst(obj)));
}
