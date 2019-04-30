/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 16:47:26 by ccollins          #+#    #+#             */
/*   Updated: 2019/04/25 16:47:30 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		maketheme(t_fdf *fdf)
{
	fdf->colors->a = 0xf4feff;
	fdf->colors->b = 0xd3f3fa;
	fdf->colors->c = 0xa2dbf2;
	fdf->colors->d = 0x84c6ed;
	fdf->colors->e = 0x65ade8;
	fdf->colors->f = 0x5f98e3;
	fdf->colors->g = 0x5577db;
	fdf->colors->h = 0x4f61d6;
	fdf->colors->i = 0x494cd1;
	fdf->colors->j = 0x4a4fb6;
	fdf->colors->k = 0x424a80;
	fdf->colors->l = 0x343b57;
	fdf->colors->back = 0x020611;
	fdf->colors->menu = 0x0a153c;
	fdf->colors->text = 0xf4feff;
}

static void	snake(t_fdf *fdf)
{
	fdf->colors->a = 0x78e08b;
	fdf->colors->b = 0x4cc37b;
	fdf->colors->c = 0x27a575;
	fdf->colors->d = 0x0b8671;
	fdf->colors->e = 0x108c86;
	fdf->colors->f = 0x158b91;
	fdf->colors->g = 0x1e7e99;
	fdf->colors->h = 0x25779f;
	fdf->colors->i = 0x2e86ab;
	fdf->colors->j = 0x40a0bd;
	fdf->colors->k = 0x53bbd0;
	fdf->colors->l = 0x5ac5d7;
	fdf->colors->back = 0x070706;
	fdf->colors->menu = 0x034744;
	fdf->colors->text = 0xf6ecd6;
}

static void	mountain(t_fdf *fdf)
{
	fdf->colors->a = 0xffffff;
	fdf->colors->b = 0x543a0f;
	fdf->colors->c = 0x785524;
	fdf->colors->d = 0x9c7440;
	fdf->colors->e = 0xbf9666;
	fdf->colors->f = 0xbea15c;
	fdf->colors->g = 0xb6ba4a;
	fdf->colors->h = 0x95b73c;
	fdf->colors->i = 0x77973b;
	fdf->colors->j = 0x85a73c;
	fdf->colors->k = 0x708f3a;
	fdf->colors->l = 0x546d33;
	fdf->colors->back = 0x060505;
	fdf->colors->menu = 0x283400;
	fdf->colors->text = 0xfdf9f9;
}

static void	ara(t_fdf *fdf, int i)
{
	fdf->colors->a = (i) ? 0xffc907 : 0xc10001;
	fdf->colors->b = (i) ? 0x03fdf9 : 0xb00000;
	fdf->colors->c = (i) ? 0x02b9fd : 0x940002;
	fdf->colors->d = (i) ? 0x03b7ee : 0x700001;
	fdf->colors->e = (i) ? 0x02aed0 : 0x6c0b4a;
	fdf->colors->f = (i) ? 0x03a4b3 : 0x391a66;
	fdf->colors->g = (i) ? 0x039395 : 0x222f62;
	fdf->colors->h = (i) ? 0x027771 : 0x2a555e;
	fdf->colors->i = (i) ? 0x027a7c : 0x376870;
	fdf->colors->j = (i) ? 0x026f88 : 0x4e858c;
	fdf->colors->k = (i) ? 0x025e94 : 0x5e999e;
	fdf->colors->l = (i) ? 0x02519c : 0x70abaf;
	fdf->colors->back = (i) ? 0x000000 : 0x0c0c0b;
	fdf->colors->menu = (i) ? 0x0d0c0c : 0x151412;
	fdf->colors->text = (i) ? 0xffc907 : 0xeff6ff;
}

void		change_theme(int key, t_fdf *fdf)
{
	if (key == 18)
		maketheme(fdf);
	if (key == 19)
		snake(fdf);
	if (key == 20)
		mountain(fdf);
	if (key == 21)
		ara(fdf, 1);
	if (key == 23)
		ara(fdf, 0);
	plot(fdf);
}
