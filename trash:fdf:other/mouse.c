/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:28:59 by ccollins          #+#    #+#             */
/*   Updated: 2019/04/25 16:29:03 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == 69 || key == 24 || key == 4)
		fdf->zoom++;
	else if (key == 78 || key == 27 || key == 5)
		fdf->zoom--;
	if (fdf->zoom < 1)
		fdf->zoom = 1;
	plot(fdf);
}

int		mouse_press(int button, int x, int y, void *param)
{
	t_fdf *fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf *)param;
	if (button == 4 || button == 5)
		zoom(button, fdf);
	else if (button == 1)
		fdf->is_pressed = 1;
	return (0);
}

int		mouse_release(int button, int x, int y, void *param)
{
	t_fdf *fdf;

	(void)x;
	(void)y;
	(void)button;
	fdf = (t_fdf *)param;
	fdf->is_pressed = 0;
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	fdf->from_x = fdf->to_x;
	fdf->from_y = fdf->to_y;
	fdf->to_x = x;
	fdf->to_y = y;
	if (fdf->is_pressed)
	{
		fdf->beta += (x - fdf->from_x) * 0.0015;
		fdf->alpha += (y - fdf->from_y) * 0.0015;
		plot(fdf);
	}
	return (0);
}

void	reset(int key, t_fdf *fdf)
{
	fdf->zoom = zoom_max(fdf->map);
	fdf->projection = 1;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
	fdf->z_divisor = 1;
	fdf->x_offset = 0;
	fdf->y_offset = 0;
	plot(fdf);
}
