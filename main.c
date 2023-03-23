/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oroy <oroy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 17:27:42 by oroy              #+#    #+#             */
/*   Updated: 2023/03/22 12:32:38 by oroy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int	fd = open("test.txt", O_RDONLY, 0);

	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	printf ("%s", get_next_line(fd));
	close(fd);
	return (0);
}
