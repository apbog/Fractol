/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:30:34 by ccollins          #+#    #+#             */
/*   Updated: 2019/04/25 16:30:39 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_fdf(t_fdf *fdf)
{
	free(fdf->map);
	free(fdf);
	exit(1);
}

void		case_exit(int i, void *smth)
{
	t_fdf *fdf;
	t_map *map;

	if (i == 0)
	{
		fdf = (t_fdf *)smth;
		free_fdf(fdf);
	}
	if (i == 1)
	{
		ft_putstr("Map error\n");
		map = (t_map *)smth;
		free(map);
	}
	if (i == -1)
		ft_putstr("Alloc error\n");
	if (i == 2)
	{
		ft_putstr("Alloc error\n");
		fdf = (t_fdf *)smth;
		free_fdf(fdf);
	}
	exit(1);
}

void		free_array(char **arr)
{
	int i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}
