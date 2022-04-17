/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlozano- <nlozano-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:34:52 by nlozano-          #+#    #+#             */
/*   Updated: 2022/04/17 12:44:40 by agalan-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void  print_3d_array2(char **A, int argc, char **argv)
{
	int i;
	int j;
	int k;
	int n;

	k = 0;
	while (argv[argc - 1][k] != '\0')
		k++;
	n = k / 3;
	if (k % 3 != 0)
		n++;
	i = 0;
	while (i < n)
	{
		j  = 0;
		while(j < 3)
		{
			printf("%c", A[i][j]);
			j++;
		}
		//write(1, "B", 1);
		printf("\n");
		i++;
	}

}

void  print_3d_array(char ***A, int *paramMtrx)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < paramMtrx[1])
	{
		j  = 0;
		while(j < 2)
		{
			k = 0;
			while (k < paramMtrx[2])
			{
				printf("%c", A[i][j][k]);
				k++;
			}
			//write(1, "A",1);	
			//printf("\n");
			j++;	
		}
		//write(1, "B", 1);
		printf("\n");
		i++;
	}

}

int deallocate_memory(char ***A, int *paramMtrx)
{
	int i;
	int j;

	i = 0;
	while(i < paramMtrx[0])
	{
		j = 0;
		while(j < paramMtrx[0])
		{
			free(A[i][j]);
			j++;
		}
		free(A[i]);
		i++;
	}
	free(A);
	return (0);
}

int deallocate_memory2(char **arg, int n)
{
	int i;

	i = 0;
	while(i < n)
	{
		free(arg[i]);
	}
	free(arg);
	return (0);
}

void	assign_values2(char ***A, int *paramMtrx, int *ijk)
{
	int	fd;
	char	buf[1] = " ";

	fd = open ("numbers.dict",O_RDONLY);
	while (ijk[0] <= paramMtrx[1])
	{
		ijk[1] = 0;
		while(buf[0] != '\n' || ijk[1] < 2)
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

void  assign_values(char ***A, int *paramMtrx)
{
	int ijk[3];

	ijk[0] = 0;
	ijk[1] = 0;
	ijk[2] = 0;
	assign_values2(A, paramMtrx, ijk);	
}
