/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:19:12 by ccollins          #+#    #+#             */
/*   Updated: 2019/05/02 19:19:15 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static void	type(int key, t_fractol *fr)
{
	if (key == 46)
		fr->type = 1;
	else if (key == 38)
		fr->type = 0;
	else if (key == 40)
		fr->type = 2;
	plot(fr);
}

static void	mode_on(int key, t_fractol *fr)
{
	if (fr->data->mode_on)
		fr->data->mode_on = 0;
	else
		fr->data->mode_on = 1;
	plot(fr);
}

static int	key_press(int key, void *param)
{
	t_fractol *fr;

	fr = (t_fractol *)param;
	if (key == 53)
		end(param);
	else if (key == 46 || key == 38 || key == 40)
		type(key, fr);
	else if ((key == 123 || key == 124 || key == 126 || key == 125) &&
		(fr->type == 0 || fr->type == 2))
		move_jul(key, fr);
	else if ((key == 123 || key == 124 || key == 126 || key == 125) &&
		(fr->type == 1))
		move_man(key, fr);
	else if (key == 49)
		mode_on(key, fr);
	return (1);
}

static int	mouse_press(int button, int x, int y, void *param)
{
	t_fractol *fr;

	fr = (t_fractol *)param;
	fr->data->to_x = x;
	fr->data->to_y = y;
	if ((button == 4 || button == 5) && (fr->type == 0 || fr->type == 2))
		zoom_jul(button, fr);
	if ((button == 4 || button == 5) && (fr->type == 1))
		zoom_man(button, fr);
	return (0);
}

void		hook(t_fractol *fr)
{
	mlx_hook(fr->win, 2, 0, key_press, fr);
	mlx_hook(fr->win, 4, 0, mouse_press, fr);
	mlx_hook(fr->win, 17, 0, end, fr);
	mlx_hook(fr->win, 6, 0, mouse_move, fr);
}
