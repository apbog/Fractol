/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:18:47 by ccollins          #+#    #+#             */
/*   Updated: 2019/04/25 16:18:52 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include <fcntl.h>

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				h;
}					t_point;

typedef struct		s_object
{
	double			x0;
	double			y0;
	double			x1;
	double			y1;
	double			xn;
	double			yn;
	int				h0;
	int				h1;
	double			a;
	double			p;
	int				color0;
	int				color1;
}					t_object;

typedef struct		s_colors
{
	int				a;
	int				b;
	int				c;
	int				d;
	int				e;
	int				f;
	int				g;
	int				h;
	int				i;
	int				j;
	int				k;
	int				l;
	int				back;
	int				menu;
	int				text;
}					t_colors;

typedef struct		s_coord
{
	int				z;
	int				color;
	struct s_coord	*next;
}					t_coord;

typedef struct		s_map
{
	int				max_width;
	int				max_height;
	int				menu_width;
	int				width;
	int				height;
	int				*coords_arr;
	int				*colors_arr;
	int				color_on;
	int				z_min;
	int				z_max;
}					t_map;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				projection;
	int				zoom;
	double			alpha;
	double			beta;
	double			gamma;
	float			z_divisor;
	int				x_offset;
	int				y_offset;
	int				is_pressed;
	int				to_x;
	int				to_y;
	int				from_x;
	int				from_y;
	t_map			*map;
	t_colors		*colors;
}					t_fdf;

t_map				*create_map(void);
t_fdf				*create_fdf(t_map *map);
t_point				create_point(int x, int y, t_map *map);
t_coord				*create_coord(char *s, t_map *map);
t_point				convert_point(t_point p, t_fdf *fdf);
int					key_press(int key, void *param);
void				zoom(int key, t_fdf *fdf);
void				reset(int key, t_fdf *fdf);
int					mouse_press(int button, int x, int y, void *param);
int					mouse_release(int button, int x, int y, void *param);
int					mouse_move(int x, int y, void *param);
void				put_line(t_point f, t_point s, t_fdf *fdf);
void				plot(t_fdf *fdf);
void				free_array(char **arr);
void				case_exit(int i, void *smth);
void				maketheme(t_fdf *fdf);
void				change_theme(int key, t_fdf *fdf);
void				color_on(int key, t_fdf *fdf);
void				create_point_from_obj(t_fdf *fdf, t_object obj);
int					zoom_max(t_map *map);
void				put_point(t_fdf *fdf, int x, int y, int color);

#endif
