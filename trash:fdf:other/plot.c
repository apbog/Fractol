/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plot.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:58:38 by ccollins          #+#    #+#             */
/*   Updated: 2019/04/20 12:58:39 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	background(t_fdf *fdf)
{
	int *array;
	int i;

	array = (int *)(fdf->data_addr);
	i = -1;
	while (++i < fdf->map->max_height * fdf->map->max_width)
	{
		if (i % fdf->map->max_width < fdf->map->menu_width)
			array[i] = fdf->colors->menu;
		else
			array[i] = fdf->colors->back;
	}
}

static void	commands2(void *mlx, void *win, int c, int a)
{
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Move:");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Up, Down, Left, Right");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Zoom");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "+/-");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Reset Settings");
	mlx_string_put(mlx, win, 5, a = a + 25, c, " - Whitespace");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Exit:");
	mlx_string_put(mlx, win, 5, a = a + 25, c, " - Esc");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Mouse commands");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Rotation:");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Press & Move");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Zoom:");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Scroll");
}

static void	commands(void *mlx, void *win, int c)
{
	int a;

	a = 5;
	mlx_string_put(mlx, win, 5, a, c, "Keyboard Commands");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Change projection:");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Parallel - P");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "ISO True - I");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "ISO 2:1 - O");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Change color theme:");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Night blue - 1");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Snake - 2");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Mountain - 3");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Ara - 4");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Strawberry - 5");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Color On/Off - C");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Rotation:");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "X-axis - W/S");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Y-axis - A/D");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Z-axis - Q/E");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Dimension:");
	mlx_string_put(mlx, win, 5, a = a + 25, c, "Up/Down-wards Arrow to Bar");
	commands2(mlx, win, c, a);
}

void		plot(t_fdf *fdf)
{
	int x;
	int y;

	background(fdf);
	x = -1;
	while (++x < fdf->map->width)
	{
		y = -1;
		while (++y < fdf->map->height)
		{
			if (x != fdf->map->width - 1)
				put_line(convert_point(create_point(x, y, fdf->map), fdf),
					convert_point(create_point(x + 1, y, fdf->map), fdf), fdf);
			if (y != fdf->map->height - 1)
				put_line(convert_point(create_point(x, y, fdf->map), fdf),
					convert_point(create_point(x, y + 1, fdf->map), fdf), fdf);
			if (fdf->map->height == 1 && fdf->map->width == 1)
				put_point(fdf, x + fdf->map->menu_width + (fdf->map->max_width
				- fdf->map->menu_width) / 2 + fdf->x_offset, y +
				(fdf->map->max_height) / 2 + (fdf->map->height * fdf->zoom)
				/ 2 + fdf->y_offset, fdf->colors->l);
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	commands(fdf->mlx, fdf->win, fdf->colors->text);
}
