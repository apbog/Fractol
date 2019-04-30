/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:27:24 by ccollins          #+#    #+#             */
/*   Updated: 2019/04/25 16:27:25 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	move(int key, t_fdf *fdf)
{
	if (key == 123)
		fdf->x_offset -= 10;
	else if (key == 124)
		fdf->x_offset += 10;
	else if (key == 126)
		fdf->y_offset -= 10;
	else
		fdf->y_offset += 10;
	plot(fdf);
}

static void	rotation(int key, t_fdf *fdf)
{
	if (key == 1)
		fdf->alpha += 0.05;
	else if (key == 13)
		fdf->alpha -= 0.05;
	else if (key == 0)
		fdf->beta -= 0.05;
	else if (key == 2)
		fdf->beta += 0.05;
	else if (key == 14)
		fdf->gamma += 0.05;
	else if (key == 12)
		fdf->gamma -= 0.05;
	plot(fdf);
}

static void	dimension(int key, t_fdf *fdf)
{
	if (key == 115)
		fdf->z_divisor = fdf->z_divisor - 0.05;
	else if (key == 119)
		fdf->z_divisor = fdf->z_divisor + 0.05;
	if (fdf->z_divisor < 0.05)
		fdf->z_divisor = 0.05;
	else if (fdf->z_divisor > 10)
		fdf->z_divisor = 10;
	plot(fdf);
}

static void	projection(int key, t_fdf *fdf)
{
	if (key == 35)
		fdf->projection = 0;
	else if (key == 34)
		fdf->projection = 1;
	else if (key == 31)
		fdf->projection = 2;
	plot(fdf);
}

int			key_press(int key, void *param)
{
	t_fdf *fdf;

	fdf = (t_fdf *)param;
	if (key == 53)
		case_exit(0, fdf);
	if (key == 69 || key == 78 || key == 24 || key == 27)
		zoom(key, fdf);
	else if (key == 123 || key == 124 || key == 126 || key == 125)
		move(key, fdf);
	else if (key == 0 || key == 1 || key == 2 || key == 12 || key == 13
			|| key == 14)
		rotation(key, fdf);
	else if (key == 115 || key == 119)
		dimension(key, fdf);
	else if (key == 35 || key == 34 || key == 31)
		projection(key, fdf);
	else if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23)
		change_theme(key, fdf);
	else if (key == 8)
		color_on(key, fdf);
	else if (key == 49)
		reset(key, fdf);
	return (0);
}
