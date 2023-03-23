/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 14:44:11 by oroy              #+#    #+#             */
/*   Updated: 2023/03/22 20:24:40 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*freeline(char *line)
{
	if (line)
		free (line);
	return (NULL);
}

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

char	*ft_strdup_gnl(char *buf, char *tmp)
{
	char	*newtmp;
	size_t	i;

	if (!buf)
		return (NULL);
	i = 0;
	newtmp = ft_calloc(ft_strlen(buf) + 1, sizeof(char));
	if (newtmp)
	{
		while (buf[i])
		{
			newtmp[i] = buf[i];
			i++;
		}
		newtmp[i] = '\0';
	}
	tmp = freeline(tmp);
	if (!newtmp)
		return (NULL);
	return (newtmp);
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
