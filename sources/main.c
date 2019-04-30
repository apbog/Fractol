#include "../includes/fractol.h"

static void background(t_froctol *fr)
{
	int *array;
	int i;

	array = (int *)(fr->data_addr);
	i = -1;
	while (++i < 2048 * 1080)
	{
		if (i % 2)
			array[i] = 0xffffff;
		else
			array[i] = 0x000000;
	}
}

void put_point(t_froctol *fr, int x, int y, int color)
{
	int *array;

	array = (int *)(fr->data_addr);
	if (x >= 0 && x < 1000 && y >= 0 &&
		y < 1000)
		array[x + y * fr->size_line / 4] = color;
}

static int		color(int from, int to, double p)
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

void mandelbrot(t_froctol *fr)
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

void julia(t_froctol *fr)
{
	int x;
	int y;
	int size;
	double k;
	t_point pnt;
	t_point new;

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
			while (k < 100)
			{
				new.x = pnt.x;
				new.y = pnt.y;
				pnt.x = pow(new.x, 2) - pow(new.y, 2) + fr->data->p;
				pnt.y = 2 * new.x *new.y + fr->data->q;
				if (pow(pnt.x, 2) + pow(pnt.y, 2) > pow(fr->data->r,2))
					break ;
				k++;
			}
			if (k == 100)
				put_point(fr, x, y, 0x111111);
			else
				put_point(fr, x, y, color(0x666699, 0x00ffcc, k / 100));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

void type(int key, t_froctol *fr)
{
	if (key == 46)
		mandelbrot(fr);
	else if (key == 38)
		julia(fr);
}

int key_press(int key, void *param)
{
	t_froctol *fr;

	fr = (t_froctol *)param;
	if (key == 53)
		exit(1);
	else if (key == 46 || key == 38)
		type(key, fr);
	return (1);
}

t_froctol *create_fract(t_data *data)
{
	t_froctol *fr;

	if (!(fr = (t_froctol *)ft_memalloc(sizeof(t_froctol))))
		exit(1);
	fr->mlx = mlx_init();
	fr->win = mlx_new_window(fr->mlx, 1500, 1000, "Fract'ol");
	fr->img = mlx_new_image(fr->mlx, 1500, 1000);
	fr->data_addr = mlx_get_data_addr(fr->img, &(fr->bits_per_pixel),
				&(fr->size_line), &(fr->endian));
	fr->data = data;			
	return (fr);
}

t_data *create_data(void)
{
	t_data *data;

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		exit(1);
	data->re_z = 1.5;
	data->im_z = 1.5;
	data->p = 0.28;
	data->q = 0.0113;
	data->r = 2;
	data->p_min = -2.5;
	data->p_max = 1.5;
	data->q_min = -2;
	data->q_max = 2;
	return(data);
}

void zoom(int key, t_froctol *fr)
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
	julia(fr);
}

int mouse_press(int button, int x, int y, void *param)
{
	t_froctol *fr;

	(void)x;
	(void)y;
	fr = (t_froctol *)param;
	if (button == 4 || button == 5)
		zoom(button, fr);
	return (0);
}

int main(int ac, char **cv)
{
	t_froctol	*fr;
	t_point pnt;
	t_data *data;


	// background(fr);
	data = create_data();
	fr = create_fract(data);
	// julia(fr);
	// mandelbrot(fr);
	mlx_hook(fr->win, 2, 0, key_press, fr);
	mlx_hook(fr->win, 4, 0, mouse_press, fr);
	mlx_loop(fr->mlx);
	return (1);
}