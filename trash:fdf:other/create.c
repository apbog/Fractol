/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:32:21 by ccollins          #+#    #+#             */
/*   Updated: 2019/04/25 16:32:24 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_map	*create_map(void)
{
	t_map *new;

	if (!(new = (t_map *)ft_memalloc(sizeof(t_map))))
		case_exit(-1, 0);
	new->max_width = 2048;
	new->max_height = 1080;
	new->menu_width = 300;
	new->width = 0;
	new->height = 0;
	new->coords_arr = NULL;
	new->colors_arr = NULL;
	new->color_on = 1;
	new->z_min = 2147483647;
	new->z_max = -2147483648;
	return (new);
}

int		zoom_max(t_map *map)
{
	if (map->z_max != 0)
		return (ft_min(ft_min((map->max_width - map->menu_width) /
			map->width / 2, map->max_height / map->height / 2),
			(map->max_height / map->z_max / 2)));
	else
		return (ft_min((map->max_width - map->menu_width) /
			map->width / 2, map->max_height / map->height / 2));
}

t_fdf	*create_fdf(t_map *map)
{
	t_fdf *fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
	{
		free(map);
		case_exit(-1, 0);
	}
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, map->max_width, map->max_height, "FdF");
	fdf->img = mlx_new_image(fdf->mlx, map->max_width, map->max_height);
	fdf->projection = 1;
	fdf->zoom = zoom_max(map);
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
	fdf->z_divisor = 1;
	fdf->x_offset = 0;
	fdf->y_offset = 0;
	fdf->data_addr = mlx_get_data_addr(fdf->img, &(fdf->bits_per_pixel),
		&(fdf->size_line), &(fdf->endian));
	fdf->map = map;
	if (!(fdf->colors = (t_colors *)ft_memalloc(sizeof(t_colors))))
		case_exit(2, fdf);
	return (fdf);
}

t_point	create_point(int x, int y, t_map *map)
{
	t_point	point;
	int		index;

	index = (y * map->width + x);
	point.x = x;
	point.y = y;
	point.z = map->coords_arr[index];
	point.color = (map->colors_arr[index] == -1) ? 0xffffff :
			map->colors_arr[index];
	point.h = map->coords_arr[index];
	return (point);
}

t_coord	*create_coord(char *s, t_map *map)
{
	t_coord	*coord;
	char	**parts;

	if (!(coord = (t_coord *)ft_memalloc(sizeof(t_coord))))
	{
		free(map);
		case_exit(-1, 0);
	}
	if (!(parts = ft_strsplit(s, ',')))
		case_exit(1, map);
	if ((!ft_isnumber(parts[0], 10))
		|| (parts[1] && !ft_isnumber(parts[1], 16)))
	{
		free_array(parts);
		case_exit(1, map);
	}
	coord->z = ft_atoi(parts[0]);
	coord->color = parts[1] ? ft_atoi_base(parts[1], 16) : -1;
	coord->next = NULL;
	free_array(parts);
	return (coord);
}
