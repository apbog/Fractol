/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:17:18 by ccollins          #+#    #+#             */
/*   Updated: 2019/05/02 19:18:01 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

t_fractol	*create_fract(t_data *data, int type)
{
	t_fractol *fr;

	if (!(fr = (t_fractol *)ft_memalloc(sizeof(t_fractol))))
		exit(1);
	fr->mlx = mlx_init();
	fr->win = mlx_new_window(fr->mlx, 1500, 1000, "Fract'ol");
	fr->img = mlx_new_image(fr->mlx, 1500, 1000);
	fr->data_addr = mlx_get_data_addr(fr->img, &(fr->bits_per_pixel),
		&(fr->size_line), &(fr->endian));
	fr->data = data;
	fr->type = type;
	fr->size = 1000;
	fr->k_max = 150;
	return (fr);
}

t_data		*create_data(void)
{
	t_data *data;

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		exit(1);
	data->re_z_max = 1.5;
	data->im_z_max = 1.5;
	data->re_z_min = -1.5;
	data->im_z_min = -1.5;
	data->p = -0.723000;
	data->q = 0.203000;
	data->r = 2;
	data->p_min = -2.5;
	data->p_max = 1.5;
	data->q_min = -2;
	data->q_max = 2;
	data->mode_on = 0;
	return (data);
}
