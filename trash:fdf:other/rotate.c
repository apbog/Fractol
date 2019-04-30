/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:31:09 by ccollins          #+#    #+#             */
/*   Updated: 2019/04/25 16:31:14 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	iso(int *x, int *y, int z, double angle)
{
	int ox;
	int oy;

	ox = *x;
	oy = *y;
	*x = (ox - oy) * cos(angle);
	*y = (ox + oy) * sin(angle) - z;
}

static void	rotate(int *x, int *y, int *z, t_fdf *fdf)
{
	int ox;
	int oy;
	int oz;

	ox = *x;
	*x = ox * cos(fdf->beta) + *z * sin(fdf->beta);
	*z = -ox * sin(fdf->beta) + *z * cos(fdf->beta);
	oy = *y;
	*y = oy * cos(fdf->alpha) + *z * sin(fdf->alpha);
	*z = -oy * sin(fdf->alpha) + *z * cos(fdf->alpha);
	ox = *x;
	oy = *y;
	*x = ox * cos(fdf->gamma) - oy * sin(fdf->gamma);
	*y = ox * sin(fdf->gamma) + oy * cos(fdf->gamma);
}

t_point		convert_point(t_point p, t_fdf *fdf)
{
	p.x = p.x * fdf->zoom - ((fdf->map->width - 1) * fdf->zoom) / 2;
	p.y = p.y * fdf->zoom - ((fdf->map->height - 1) * fdf->zoom) / 2;
	p.z *= fdf->zoom / fdf->z_divisor;
	rotate(&p.x, &p.y, &p.z, fdf);
	if (fdf->projection == 1)
		iso(&p.x, &p.y, p.z, 0.523599);
	else if (fdf->projection == 2)
		iso(&p.x, &p.y, p.z, 0.46373398);
	p.x += fdf->map->menu_width + (fdf->map->max_width - fdf->map->menu_width)
			/ 2 + fdf->x_offset;
	p.y += (fdf->map->max_height) / 2 + (fdf->map->height * fdf->zoom)
			/ 2 + fdf->y_offset;
	return (p);
}

void		color_on(int key, t_fdf *fdf)
{
	if (fdf->map->color_on)
		fdf->map->color_on = 0;
	else
		fdf->map->color_on = 1;
	plot(fdf);
}
