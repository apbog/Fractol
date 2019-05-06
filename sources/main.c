/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:19:27 by ccollins          #+#    #+#             */
/*   Updated: 2019/05/02 19:19:31 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	howto(void)
{
	ft_putstr("Usage: ./fractol + key:\n     Julia\n");
	ft_putstr("     Mandelbrot\n     Julia3\n");
}

int			main(int ac, char **cv)
{
	t_fractol	*fr;
	t_data		*data;
	int			type;

	if (ac == 2 && (!ft_strcmp("Julia", cv[1]) || !ft_strcmp("Mandelbrot",
			cv[1]) || !ft_strcmp("Julia3", cv[1])))
	{
		if (!ft_strcmp("Julia", cv[1]))
			type = 0;
		else if (!ft_strcmp("Mandelbrot", cv[1]))
			type = 1;
		else if (!ft_strcmp("Julia3", cv[1]))
			type = 2;
	}
	else
	{
		howto();
		return (0);
	}
	data = create_data();
	fr = create_fract(data, type);
	plot(fr);
	hook(fr);
	mlx_loop(fr->mlx);
	return (1);
}
