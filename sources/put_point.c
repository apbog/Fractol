/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_point.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 19:20:09 by ccollins          #+#    #+#             */
/*   Updated: 2019/05/02 19:20:12 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	put_point(t_fractol *fr, int x, int y, int color)
{
	int *array;

	array = (int *)(fr->data_addr);
	if (x >= 0 && x < fr->size && y >= 0 &&
		y < fr->size)
		array[x + y * fr->size_line / 4] = color;
}
