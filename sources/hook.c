#include "../includes/fractol.h"
#include <stdio.h>

void type(int key, t_fractol *fr)
{
	if (key == 46)
		fr->type = 1;
	else if (key == 38)
		fr->type = 0;
	else if (key == 40)
		fr->type = 2;
	plot(fr);
}

void mode_on(int key, t_fractol *fr)
{
	if (fr->data->mode_on)
		fr->data->mode_on = 0;
	else
		fr->data->mode_on = 1;
	plot(fr);
}

void calc_zoom(t_point *p, t_fractol *fr)
{
	p->x0 = 0.5;
	p->y0 = 0.5;
	p->x1 = fr->data->re_z_max - fr->data->re_z_min;
	p->y1 = fr->data->im_z_max - fr->data->im_z_min;
}

void calc_zoom_man(t_point *p, t_fractol *fr)
{
	p->x0 = 0.5;
	p->y0 = 0.5;
	p->x1 = fr->data->p_max - fr->data->p_min;
	p->y1 = fr->data->q_max - fr->data->q_min;
}

static void move_jul(int key, t_fractol *fr)
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

static void move_man(int key, t_fractol *fr)
{
	t_point p;

	calc_zoom(&p, fr);
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

int key_press(int key, void *param)
{
	t_fractol *fr;

	fr = (t_fractol *)param;
	if (key == 53)
		exit(1);
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

void zoom_jul(int key, t_fractol *fr)
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

void zoom_man(int key, t_fractol *fr)
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

int end(void *param)
{
	(void)param;
	exit(1);
	return (0);
}

int mouse_press(int button, int x, int y, void *param)
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

int mouse_move(int x, int y, void *param)
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

void hook(t_fractol *fr)
{
	mlx_hook(fr->win, 2, 0, key_press, fr);
	mlx_hook(fr->win, 4, 0, mouse_press, fr);
	mlx_hook(fr->win, 17, 0, end, fr);
	mlx_hook(fr->win, 6, 0, mouse_move, fr);
}