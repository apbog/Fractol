#include "../includes/fractol.h"

static void put_point(t_fractol *fr, int x, int y, int color)
{
	int *array;

	array = (int *)(fr->data_addr);
	if (x >= 0 && x < fr->size && y >= 0 &&
		y < fr->size)
		array[x + y * fr->size_line / 4] = color;
}

static int color(double p)
{
	if (p == 1)
		return (0x000000);
	else if (p > 0.9)
		return (0x00f9ff);
	else if (p > 0.8)
		return (0x00ff38);
	else if (p > 0.7)
		return (0xfdff00);
	else if (p > 0.6)
		return (0xfd00ff);
	else if (p > 0.5)
		return (0x01df01);
	else if (p > 0.4)
		return (0x8904b1);
	else if (p > 0.3)
		return (0x6a0888);
	else if (p > 0.2)
		return (0x0b610b);
	else if (p > 0.1)
		return (0xc2d6d6);
	else if (p > 0.0)
		return (0xd1e0e0);
	return (0xe0ebeb);
}

static double calc_r(t_fractol *fr)
{
	double r;

	r = (1 + sqrt(1 + 4 * (pow(fr->data->p, 2) + pow(fr->data->q, 2))) / 2);
	return (r);
}

void calc_z0(t_point *p, t_fractol *fr)
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

void calc_zn(t_point *p, t_fractol *fr)
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

static void julia(t_fractol *fr)
{
	t_point p;

	p.x = -1;
	fr->data->r = calc_r(fr);
	while (++p.x < fr->size)
	{
		p.y = -1;
		while (++p.y < fr->size)
		{
			calc_z0(&p, fr);
			p.k = 0;
			while (p.k < fr->k_max)
			{
				calc_zn(&p, fr);
				if (pow(p.x0, 2) + pow(p.y0, 2) > pow(fr->data->r, 2))
					break;
				p.k++;
			}
			put_point(fr, p.x, p.y, color(p.k / fr->k_max));
		}
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

static void mandelbrot(t_fractol *fr)
{
	t_point p;

	p.x = -1;
	while (++p.x < fr->size)
	{
		p.y = -1;
		while (++p.y < fr->size)
		{
			calc_z0(&p, fr);
			p.k = 0;
			p.x0 = 0;
			p.y0 = 0;
			while (p.k < fr->k_max)
			{
				calc_zn(&p, fr);
				if (pow(p.x0, 2) + pow(p.y0, 2) > 4)
					break;
				p.k++;
			}
			put_point(fr, p.x, p.y, color(p.k / fr->k_max));
		}
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

static void commands(void *mlx, void *win, int c)
{
	int a;

	a = 15;
	mlx_string_put(mlx, win, 1025, a, c, "Commands:");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "Change type:");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "Julia - J");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "Mandelbrot - M");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "Julia^3 - K");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "Change Julia parameter");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, " - Whitespace");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "&& Mouse Move");
	mlx_string_put(mlx, win, 1025, a = a + 25, c, "Zoom - Mouse scroll");
}

void plot(t_fractol *fr)
{
	if (fr->type == 0)
		julia(fr);
	if (fr->type == 1)
		mandelbrot(fr);
	if (fr->type == 2)
		julia(fr);
	commands(fr->mlx, fr->win, 0xfdfdfd);
}