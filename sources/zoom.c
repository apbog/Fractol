/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:20:21 by ccollins          #+#    #+#             */
/*   Updated: 2019/05/02 19:20:25 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	calc_zoom(t_point *p, t_fractol *fr)
{
	p->x0 = 0.5;
	p->y0 = 0.5;
	p->x1 = fr->data->re_z_max - fr->data->re_z_min;
	p->y1 = fr->data->im_z_max - fr->data->im_z_min;
}

void	calc_zoom_man(t_point *p, t_fractol *fr)
{
	p->x0 = 0.5;
	p->y0 = 0.5;
	p->x1 = fr->data->p_max - fr->data->p_min;
	p->y1 = fr->data->q_max - fr->data->q_min;
}

void	zoom_jul(int key, t_fractol *fr)
{
	t_point p;

	calc_zoom(&p, fr);
	if (fr->data->to_x >= 0 && fr->data->to_x <= 1000 &&
		fr->data->to_y >= 0 && fr->data->to_y <= 1000)
	{
		p.x0 = (double)fr->data->to_x / 1000;
		p.y0 = (double)fr->data->to_y / 1000;
	}
	if (key == 4)
	{
		fr->data->re_z_max -= (1 - p.x0) * 0.1 * p.x1;
		fr->data->re_z_min += p.x0 * 0.1 * p.x1;
		fr->data->im_z_max -= (1 - p.y0) * 0.1 * p.y1;
		fr->data->im_z_min += p.y0 * 0.1 * p.y1;
	}
	else if (key == 5)
	{
		fr->data->re_z_max += (1 - p.x0) * 0.1 * p.x1;
		fr->data->re_z_min -= p.x0 * 0.1 * p.x1;
		fr->data->im_z_max += (1 - p.y0) * 0.1 * p.y1;
		fr->data->im_z_min -= p.y0 * 0.1 * p.y1;
	}
	plot(fr);
}

void	zoom_man(int key, t_fractol *fr)
{
	t_point p;

	calc_zoom_man(&p, fr);
	if (fr->data->to_x >= 0 && fr->data->to_x <= 1000 &&
		fr->data->to_y >= 0 && fr->data->to_y <= 1000)
	{
		p.x0 = (double)fr->data->to_x / 1000;
		p.y0 = (double)fr->data->to_y / 1000;
	}
	if (key == 4)
	{
		fr->data->p_max -= (1 - p.x0) * 0.1 * p.x1;
		fr->data->p_min += p.x0 * 0.1 * p.x1;
		fr->data->q_max -= (1 - p.y0) * 0.1 * p.y1;
		fr->data->q_min += p.y0 * 0.1 * p.y1;
	}
	else if (key == 5)
	{
		fr->data->p_max += (1 - p.x0) * 0.1 * p.x1;
		fr->data->p_min -= p.x0 * 0.1 * p.x1;
		fr->data->q_max += (1 - p.y0) * 0.1 * p.y1;
		fr->data->q_min -= p.y0 * 0.1 * p.y1;
	}
	plot(fr);
}
