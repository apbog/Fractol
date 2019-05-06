/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:17:03 by ccollins          #+#    #+#             */
/*   Updated: 2019/05/02 19:17:07 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

double	calc_r(t_fractol *fr)
{
	double r;

	r = (1 + sqrt(1 + 4 * (pow(fr->data->p, 2) + pow(fr->data->q, 2))) / 2);
	return (r);
}

void	calc_z0(t_point *p, t_fractol *fr)
{
	if (fr->type != 1)
	{
		p->x0 = (double)p->x / fr->size * (fr->data->re_z_max -
			fr->data->re_z_min) + fr->data->re_z_min;
		p->y0 = (double)p->y / fr->size * (fr->data->im_z_max -
			fr->data->im_z_min) + fr->data->im_z_min;
	}
	else
	{
		p->p = (double)p->x / fr->size * (fr->data->p_max - fr->data->p_min)
			+ fr->data->p_min;
		p->q = (double)p->y / fr->size * (fr->data->q_max - fr->data->q_min)
			+ fr->data->q_min;
	}
}

void	calc_zn(t_point *p, t_fractol *fr)
{
	if (fr->type == 0)
	{
		p->x1 = p->x0;
		p->y1 = p->y0;
		p->x0 = pow(p->x1, 2) - pow(p->y1, 2) + fr->data->p;
		p->y0 = 2 * p->x1 * p->y1 + fr->data->q;
	}
	else if (fr->type == 2)
	{
		p->x1 = p->x0;
		p->y1 = p->y0;
		p->x0 = pow(p->x1, 3) - 3 * p->x1 * pow(p->y1, 2) + fr->data->p;
		p->y0 = 3 * pow(p->x1, 2) * p->y1 - pow(p->y1, 3) + fr->data->q;
	}
	else if (fr->type == 1)
	{
		p->x1 = p->x0;
		p->y1 = p->y0;
		p->x0 = pow(p->x1, 2) - pow(p->y1, 2) + p->p;
		p->y0 = 2 * p->x1 * p->y1 + p->q;
	}
}
