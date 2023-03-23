/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:10:17 by oroy              #+#    #+#             */
/*   Updated: 2023/03/22 20:11:28 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static size_t	getbuflength(char *buf, unsigned char *n)
{
	size_t	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			*n = 1;
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

static char	*createline(char *line, char *buf, char **tmp, unsigned char *n)
{
	char	*newline;
	char	*ptr;
	size_t	len;

	if (*tmp)
		ptr = *tmp;
	else
		ptr = buf;
	len = getbuflength(ptr, n);
	newline = ft_calloc(ft_strlen(line) + len + 1, sizeof(char));
	if (newline)
		newline = ft_strjoin_gnl(newline, line, ptr, len);
	if (ptr[len])
		*tmp = ft_strdup_gnl(&ptr[len], *tmp);
	else
		*tmp = freeline(*tmp);
	line = freeline(line);
	if (!newline)
		return (NULL);
	return (newline);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	ssize_t			readvalue;
	char			*line;
	static char		*tmp;
	unsigned char	n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	n = 0;
	readvalue = BUFFER_SIZE;
	while (!n && readvalue == BUFFER_SIZE)
	{
		if (!tmp)
		{
			readvalue = read(fd, buf, BUFFER_SIZE);
			if (readvalue == -1)
				line = freeline(line);
			if (readvalue <= 0)
				break ;
			buf[readvalue] = '\0';
		}
		line = createline(line, buf, &tmp, &n);
	}
	return (line);
}
