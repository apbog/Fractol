/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 14:48:46 by ccollins          #+#    #+#             */
/*   Updated: 2019/02/26 14:49:10 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	i = 0;
	c1 = (unsigned char *)dst;
	c2 = (unsigned char *)src;
	while (i < n)
	{
		c1[i] = c2[i];
		if (c1[i] == (unsigned char)c)
			return (c1 + i + 1);
		i++;
	}
	return (NULL);
}
