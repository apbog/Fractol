/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:44:06 by ccollins          #+#    #+#             */
/*   Updated: 2019/02/26 15:44:13 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	retlen;
	int		i;

	i = 0;
	if (!s || !f)
		return (NULL);
	retlen = ft_strlen(s);
	if (!(ret = ft_memalloc(retlen + 1)))
		return (NULL);
	while (*s)
	{
		ret[i] = f(i, *s);
		i++;
		s++;
	}
	return (ret);
}
