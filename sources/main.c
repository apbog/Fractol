#include "../includes/fractol.h"

int	main(int ac, char **cv)
{
	t_fractol	*fr;
	t_data		*data;
	int			type;

	if (ac == 2 && (!ft_strcmp("Julia", cv[1]) || !ft_strcmp("Mandelbrot",
	 cv[1]) || !ft_strcmp("Other", cv[1])))
	{
		if (!ft_strcmp("Julia", cv[1]))
			type  = 0;
		else if (!ft_strcmp("Mandelbrot", cv[1]))
			type = 1;
		else if (!ft_strcmp("Other", cv[1]))
			type = 2;
	}
	else
	{
		ft_putstr("Usage: ./fractol + key:\n     Julia\n     Mandelbrot\n     Other\n");
		return (0);
	}
	data = create_data();
	fr = create_fract(data, type);
	plot(fr);
	hook(fr);
	mlx_loop(fr->mlx);
	return (1);
}