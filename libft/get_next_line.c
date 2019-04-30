/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccollins <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:33:28 by ccollins          #+#    #+#             */
/*   Updated: 2019/03/06 17:33:29 by ccollins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strchr_int(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

int	workline(char **cnst, int fd, char **line)
{
	int		len;
	char	*timebuf;

	if ((len = ft_strchr_int(cnst[fd], '\n')) == -1)
	{
		*line = ft_strdup(cnst[fd]);
		ft_strdel(&cnst[fd]);
		return (1);
	}
	*line = ft_strsub(cnst[fd], 0, len);
	timebuf = ft_strdup(cnst[fd] + len + 1);
	free(cnst[fd]);
	cnst[fd] = timebuf;
	if (cnst[fd][0] == '\0')
		ft_strdel(&cnst[fd]);
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char		*cnst[MAX_FD];
	char			buf[BUFF_SIZE + 1];
	int				a;
	char			*timebuf;

	if (fd < 0 || fd >= MAX_FD || line == NULL || !(read(fd, *line, 0) > -1))
		return (-1);
	while ((a = (read(fd, buf, BUFF_SIZE))) > 0)
	{
		buf[a] = '\0';
		if (cnst[fd] == NULL)
			cnst[fd] = ft_strnew(1);
		timebuf = ft_strjoin(cnst[fd], buf);
		free(cnst[fd]);
		cnst[fd] = timebuf;
		if (ft_strchr_int(cnst[fd], '\n') > -1)
			break ;
	}
	if (a < 0 || (a == 0 && !cnst[fd]))
		return (a);
	return (workline(cnst, fd, line));
}
