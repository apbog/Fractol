#include "../includes/fractol.h"

void type(int key, t_fractol *fr)
{
	if (key == 46)
		fr->type = 1;
	else if (key == 38)
		fr->type = 0;
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

int key_press(int key, void *param)
{
	t_fractol *fr;

	fr = (t_fractol *)param;
	if (key == 53)
		exit(1);
	else if (key == 46 || key == 38)
		type(key, fr);
	else if (key == 49)
		mode_on(key, fr);
	return (1);
}

void zoom(int key, t_fractol *fr)
{
	if (key == 4)
	{
		fr->data->re_z = fr->data->re_z * 0.9;
		fr->data->im_z = fr->data->im_z * 0.9;
	}
	else if (key == 5)
	{
		fr->data->re_z = fr->data->re_z * 1.1;
		fr->data->im_z = fr->data->im_z * 1.1;
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

	(void)x;
	(void)y;
	fr = (t_fractol *)param;
	if (button == 4 || button == 5)
		zoom(button, fr);
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
	if (fr->data->mode_on && fr->type == 0)
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