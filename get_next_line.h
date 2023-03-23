/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 16:29:41 by oroy              #+#    #+#             */
/*   Updated: 2023/03/23 18:56:05 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin_gnl(char *newline, char *line, char *buf, size_t buf_len);
size_t	ft_strlen(const char *s);
size_t	getbuflength(char *buf, unsigned char *n);
char	*get_next_line(int fd);

#endif