#include "../includes/fractol.h"

t_fractol *create_fract(t_data *data, int type)
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
	return (fr);
}

t_data *create_data(void)
{
	t_data *data;

	if (!(data = (t_data *)ft_memalloc(sizeof(t_data))))
		exit(1);
	data->re_z = 1.5;
	data->im_z = 1.5;
	data->p = -0.74543; // 0.28;
	data->q = -0.11301; // 0.0113;
	data->r = 1.5;		// 2;
	data->p_min = -2.5;
	data->p_max = 1.5;
	data->q_min = -2;
	data->q_max = 2;
	data->mode_on = 0;
	return (data);
}