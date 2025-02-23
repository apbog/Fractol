/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:16:45 by ccollins          #+#    #+#             */
/*   Updated: 2019/05/02 19:16:49 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include <fcntl.h>

typedef struct	s_data
{
	double		re_z_min;
	double		re_z_max;
	double		im_z_min;
	double		im_z_max;
	double		p;
	double		q;
	double		p_min;
	double		p_max;
	double		q_min;
	double		q_max;
	double		r;
	int			from_x;
	int			from_y;
	int			to_x;
	int			to_y;
	int			mode_on;
}				t_data;

typedef struct	s_fractol
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			type;
	int			size;
	int			k_max;
	t_data		*data;
}				t_fractol;

typedef struct	s_point
{
	int			x;
	int			y;
	double		k;
	double		x0;
	double		y0;
	double		x1;
	double		y1;
	double		p;
	double		q;
}				t_point;

void			hook(t_fractol *fr);
void			plot(t_fractol *fr);
t_data			*create_data(void);
t_fractol		*create_fract(t_data *data, int type);
void			put_point(t_fractol *fr, int x, int y, int color);
double			calc_r(t_fractol *fr);
void			calc_z0(t_point *p, t_fractol *fr);
void			calc_zn(t_point *p, t_fractol *fr);
void			calc_zoom(t_point *p, t_fractol *fr);
void			calc_zoom_man(t_point *p, t_fractol *fr);
void			zoom_jul(int key, t_fractol *fr);
void			zoom_man(int key, t_fractol *fr);
void			move_jul(int key, t_fractol *fr);
void			move_man(int key, t_fractol *fr);
int				mouse_move(int x, int y, void *param);
int				end(void *param);

#endif
