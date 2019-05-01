#include "../includes/fractol.h"

static void put_point(t_fractol *fr, int x, int y, int color)
{
	int *array;

	array = (int *)(fr->data_addr);
	if (x >= 0 && x < 1000 && y >= 0 &&
		y < 1000)
		array[x + y * fr->size_line / 4] = color;
}

static int color(int from, int to, double p)
{
	int r;
	int g;
	int b;

	if (from == to)
		return (from);
	r = (from / 65536) * (1 - p) + (to / 65536) * p;
	g = ((from % 65536) / 256) * (1 - p) + ((to % 65536) / 256) * p;
	b = (from % 256) * (1 - p) + (to % 256) * p;
	return (r * 65536 + g * 256 + b);
}

static void mandelbrot(t_fractol *fr)
{
	double x;
	double y;
	double k;
	double p;
	double q;
	t_point pnt;
	t_point new;

	x = 0;
	while (x < 1000)
	{
		y = 0;
		while (y < 1000)
		{
			p = x / 1000 * (fr->data->p_max - fr->data->p_min) + fr->data->p_min;
			q = y / 1000 * (fr->data->q_max - fr->data->q_min) + fr->data->q_min;
			k = 0;
			pnt.x = 0;
			pnt.y = 0;
			while (k < 100)
			{
				new.x = pnt.x;
				new.y = pnt.y;
				pnt.x = pow(new.x, 2) - pow(new.y, 2) + p;
				pnt.y = 2 * new.x *new.y + q;
				if (pow(pnt.x, 2) + pow(pnt.y, 2) > pow(fr->data->r, 2))
					break;
				k++;
			}
			if (k == 100)
				put_point(fr, x, y, 0x111111);
			else
				put_point(fr, x, y, 0xdddddd);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

static void julia(t_fractol *fr)
{
	int x;
	int y;
	int size;
	double k;
	t_point pnt;
	t_point new;
	int k_max;

	k_max = 250;
	size = 1000;
	x = 0;
	while (x < size)
	{
		y = 0;
		while (y < size)
		{
			pnt.x = (double)x / size * fr->data->re_z * 2 - fr->data->re_z;
			pnt.y = (double)y / size * fr->data->im_z * 2 - fr->data->im_z;
			k = 0;
			while (k < k_max)
			{
				new.x = pnt.x;
				new.y = pnt.y;
				pnt.x = pow(new.x, 2) - pow(new.y, 2) + fr->data->p;
				pnt.y = 2 * new.x *new.y + fr->data->q;
				if (pow(pnt.x, 2) + pow(pnt.y, 2) > 4) //pow(fr->data->r,2))
					break;
				k++;
			}
			if (k == k_max)
				put_point(fr, x, y, 0x111111);
			else
				put_point(fr, x, y, color(0x666699, 0x00ffcc, k / k_max));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

void plot(t_fractol *fr)
{
	if (fr->type == 0)
		julia(fr);
	if (fr->type == 1)
		mandelbrot(fr);
	if (fr->type == 2)
		julia(fr);
}