/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:44:44 by ccollins          #+#    #+#             */
/*   Updated: 2019/02/26 15:45:10 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *destptr, char *srcptr, size_t num)
{
	int	i;
	int	j;

	i = 0;
	while (destptr[i] != '\0')
		i++;
	j = 0;
	while (srcptr[j] != '\0' && j < (int)num)
	{
		destptr[i] = srcptr[j];
		i++;
		j++;
	}
	destptr[i] = '\0';
	return (destptr);
}
