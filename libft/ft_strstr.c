/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 15:52:52 by ccollins          #+#    #+#             */
/*   Updated: 2019/02/26 15:53:12 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int pos;
	unsigned int i;

	if (!needle[0])
		return ((char *)haystack);
	pos = 0;
	while (haystack[pos] != '\0')
	{
		if (haystack[pos] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[pos + i] == needle[i])
				++i;
			if (needle[i] == '\0')
				return ((char *)&haystack[pos]);
		}
		++pos;
	}
	return (0);
}
