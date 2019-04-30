/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:34:50 by ccollins          #+#    #+#             */
/*   Updated: 2019/02/26 14:38:14 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*str;
	int			i;
	long int	ntmp;

	i = ft_nbrlen(n);
	ntmp = n;
	ntmp = (n < 0) ? (long int)-ntmp : (long int)ntmp;
	if (!(str = ft_memalloc((size_t)i + 1)))
		return (NULL);
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = (ntmp % 10) + 48;
		ntmp = ntmp / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
