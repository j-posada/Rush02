/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_assign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jposada- <jposada-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:51:26 by jposada-          #+#    #+#             */
/*   Updated: 2022/04/17 22:56:02 by jposada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	assign_values2(char ***A, int *paramMtrx, int *ijk, char *filename)
{
	int		fd;
	char	buf[1];

	buf[0] = ' ';
	fd = open (filename, O_RDONLY);
	while (ijk[0] <= paramMtrx[1])
	{
		ijk[1] = 0;
		while (buf[0] != '\n' || ijk[1] < 2)
		{
			ijk[2] = 0;
			while ((buf[0] != ':' && buf[0] != '\n') || ijk[2] < paramMtrx[2])
			{
				read (fd, buf, 1);
				if ((buf[0] != ':') && (buf[0] != '\n'))
					A[ijk[0]][ijk[1]][ijk[2]] = buf[0];
				else
					break ;
				ijk[2] = ijk[2] + 1;
			}
			ijk[1] = ijk[1] + 1;
		}
		ijk[0] = ijk[0] + 1;
	}
	close(fd);
}

void	assign_values(char ***A, int *paramMtrx, char *filename)
{
	int	ijk[3];

	ijk[0] = 0;
	ijk[1] = 0;
	ijk[2] = 0;
	assign_values2(A, paramMtrx, ijk, filename);
}
