/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:44:11 by oroy              #+#    #+#             */
/*   Updated: 2023/03/22 20:11:54 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	total;
	size_t	i;

	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	i = 0;
	total = count * size;
	mem = malloc(total * (sizeof(unsigned char)));
	if (!mem)
		return (NULL);
	while (i < total)
	{
		*((unsigned char *)mem + i) = '\0';
		i++;
	}
	return (mem);
}

char	*ft_strjoin_gnl(char *newline, char *line, char *buf, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (line && line[i])
	{
		newline[i] = line[i];
		i++;
	}
	while (j < len)
	{
		newline[i + j] = buf[j];
		j++;
	}
	newline[i + j] = '\0';
	return (newline);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	getbuflength(char *buf, unsigned char *n)
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
