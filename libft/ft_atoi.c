/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:05:27 by ccollins          #+#    #+#             */
/*   Updated: 2019/02/26 14:17:10 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	invisible(const char c)
{
	if (c == ' ' || c == '\t' || c == '\r'
		|| c == '\n' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	int			index;
	int			i;
	long int	lres;
	int			n;

	index = 0;
	while (str[index] != '\0' && invisible(str[index]))
		index++;
	i = index;
	lres = 0;
	n = (str[i] == '-') ? 1 : 0;
	while (str[i] != '\0' && (ft_isdigit(str[i]) ||
				(i == index && (str[i] == '-' || str[i] == '+'))))
	{
		if (ft_isdigit(str[i]))
		{
			if (!((lres * 10 + (str[i] - 48) - (str[i] - 48)) / 10 == lres))
				return (n) ? 0 : -1;
			lres = (lres * 10) + (str[i] - 48);
		}
		++i;
	}
	if (n)
		lres *= -1;
	return (lres);
}
