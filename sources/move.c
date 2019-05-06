/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:19:44 by ccollins          #+#    #+#             */
/*   Updated: 2019/05/02 19:19:48 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	move_jul(int key, t_fractol *fr)
{
	t_point p;

	calc_zoom(&p, fr);
	if (key == 123)
	{
		fr->data->re_z_max -= 0.05 * p.x1;
		fr->data->re_z_min -= 0.05 * p.x1;
	}
	else if (key == 124)
	{
		fr->data->re_z_max += 0.05 * p.x1;
		fr->data->re_z_min += 0.05 * p.x1;
	}
	else if (key == 126)
	{
		fr->data->im_z_max -= 0.05 * p.y1;
		fr->data->im_z_min -= 0.05 * p.y1;
	}
	else
	{
		fr->data->im_z_max += 0.05 * p.y1;
		fr->data->im_z_min += 0.05 * p.y1;
	}
	plot(fr);
}

void	move_man(int key, t_fractol *fr)
{
	t_point p;

	calc_zoom_man(&p, fr);
	if (key == 123)
	{
		fr->data->p_max -= 0.05 * p.x1;
		fr->data->p_min -= 0.05 * p.x1;
	}
	else if (key == 124)
	{
		fr->data->p_max += 0.05 * p.x1;
		fr->data->p_min += 0.05 * p.x1;
	}
	else if (key == 126)
	{
		fr->data->q_max -= 0.05 * p.y1;
		fr->data->q_min -= 0.05 * p.y1;
	}
	else
	{
		fr->data->q_max += 0.05 * p.y1;
		fr->data->q_min += 0.05 * p.y1;
	}
	plot(fr);
}

int		mouse_move(int x, int y, void *param)
{
	t_fractol *fr;

	fr = (t_fractol *)param;
	fr->data->from_x = fr->data->to_x;
	fr->data->from_y = fr->data->to_y;
	fr->data->to_x = x;
	fr->data->to_y = y;
	if (fr->data->mode_on && (fr->type == 0 || fr->type == 2))
	{
		fr->data->p += (x - fr->data->from_x) * 0.001;
		fr->data->q += (y - fr->data->from_y) * 0.001;
		plot(fr);
	}
	return (0);
}
