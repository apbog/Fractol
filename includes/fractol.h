#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include <fcntl.h>

typedef struct s_data
{
	double re_z;
	double im_z;
	double p;
	double p_min;
	double p_max;
	double q;
	double q_min;
	double q_max;
	double r;
} t_data;

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	t_data		*data;
}				t_froctol;

typedef struct	s_point
{
	double x;
	double y;
	double z;
}				t_point;


#endif
