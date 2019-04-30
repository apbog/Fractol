/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:58:19 by ccollins          #+#    #+#             */
/*   Updated: 2019/04/20 12:58:21 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	parse_line(char **coords_line, t_coord **coords_stack, t_map *map)
{
	int		width;
	t_coord	*elem;

	width = 0;
	while (*coords_line)
	{
		elem = create_coord(*(coords_line++), map);
		elem->next = *coords_stack;
		*coords_stack = elem;
		width++;
	}
	if (map->height == 0)
		map->width = width;
	else if (map->width != width)
		case_exit(1, map);
}

static int	read_data(int fd, t_coord **coords, t_map *map)
{
	char	*line;
	int		a;
	char	**coords_line;

	while ((a = get_next_line(fd, &line)) == 1)
	{
		if (!(coords_line = ft_strsplit(line, ' ')))
			case_exit(1, map);
		if (!coords_line[0])
			case_exit(1, map);
		parse_line(coords_line, coords, map);
		free_array(coords_line);
		ft_strdel(&line);
		map->height++;
	}
	if (a == -1)
	{
		ft_putstr("File error\n");
		free(map);
		exit(1);
	}
	if (!(*coords) || map->width == 0)
		case_exit(1, map);
	return (a);
}

static void	stack_to_arrays(t_coord **coords_stack, t_map *map,
		size_t arr_size, int i)
{
	t_coord	*coord;

	if (!(map->coords_arr = (int *)ft_memalloc(arr_size)) ||
		!(map->colors_arr = (int *)ft_memalloc(arr_size)))
	{
		free(map);
		case_exit(-1, 0);
	}
	i = map->width * map->height;
	coord = *coords_stack;
	*coords_stack = (*coords_stack)->next;
	while (coord && --i >= 0)
	{
		map->coords_arr[i] = coord->z;
		map->colors_arr[i] = coord->color;
		if (coord->color != -1)
			map->color_on = 0;
		if (coord->z > map->z_max)
			map->z_max = coord->z;
		if (coord->z < map->z_min)
			map->z_min = coord->z;
		free(coord);
		coord = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
}

static void	fdf(int fd)
{
	t_map	*map;
	t_coord	*coord;
	t_fdf	*fdf;

	map = create_map();
	read_data(fd, &coord, map);
	stack_to_arrays(&coord, map, map->width * map->height * sizeof(int), 1);
	fdf = create_fdf(map);
	maketheme(fdf);
	plot(fdf);
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 0, mouse_move, fdf);
	mlx_loop(fdf->mlx);
}

int			main(int ac, char **cv)
{
	int	fd;

	if (ac == 2)
	{
		if (!((fd = open(cv[1], O_RDONLY)) >= 0))
		{
			ft_putstr("File error\n");
			return (0);
		}
		fdf(fd);
	}
	else
		ft_putstr("Usage: ./fdf + name_of_map.fdf\n");
	return (1);
}
