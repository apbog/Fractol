/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 19:56:09 by ccollins          #+#    #+#             */
/*   Updated: 2019/04/25 19:56:11 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static double	ft_abs(double a)
{
	return (a > 0) ? a : -a;
}

static t_object	create_object2(t_point f, t_point s)
{
	t_object obj;

	obj.x0 = (f.y < s.y) ? f.x : s.x;
	obj.x1 = (f.y > s.y) ? f.x : s.x;
	obj.y0 = (f.y < s.y) ? f.y : s.y;
	obj.y1 = (f.y > s.y) ? f.y : s.y;
	obj.a = (obj.x1 - obj.x0) / (obj.y1 - obj.y0);
	obj.xn = obj.x0;
	obj.yn = obj.y0;
	obj.h0 = (f.y < s.y) ? f.h : s.h;
	obj.h1 = (f.y > s.y) ? f.h : s.h;
	obj.color0 = (f.y < s.y) ? f.color : s.color;
	obj.color1 = (f.y > s.y) ? f.color : s.color;
	obj.p = 0;
	return (obj);
}

static t_object	create_object(t_point f, t_point s)
{
	t_object obj;

	if (ft_abs(s.x - f.x) > ft_abs(f.y - s.y))
	{
		obj.x0 = (f.x < s.x) ? f.x : s.x;
		obj.x1 = (f.x > s.x) ? f.x : s.x;
		obj.y0 = (f.x < s.x) ? f.y : s.y;
		obj.y1 = (f.x > s.x) ? f.y : s.y;
		obj.a = (obj.y1 - obj.y0) / (obj.x1 - obj.x0);
		obj.xn = obj.x0;
		obj.yn = obj.y0;
		obj.h0 = (f.x < s.x) ? f.h : s.h;
		obj.h1 = (f.x > s.x) ? f.h : s.h;
		obj.color0 = (f.x < s.x) ? f.color : s.color;
		obj.color1 = (f.x > s.x) ? f.color : s.color;
		obj.p = 1;
	}
	else
		return (create_object2(f, s));
	return (obj);
}

void			put_line(t_point f, t_point s, t_fdf *fdf)
{
	t_object obj;

	obj = create_object(f, s);
	if (obj.p)
	{
		while (obj.xn < obj.x1)
		{
			create_point_from_obj(fdf, obj);
			obj.xn = obj.xn + 0.5;
			obj.yn = obj.yn + obj.a * 0.5;
		}
	}
	else
	{
		while (obj.yn < obj.y1)
		{
			create_point_from_obj(fdf, obj);
			obj.yn = obj.yn + 0.5;
			obj.xn = obj.xn + obj.a * 0.5;
		}
	}
}
