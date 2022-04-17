/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlozano- <nlozano-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 20:34:52 by nlozano-          #+#    #+#             */
/*   Updated: 2022/04/17 22:51:02 by jposada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	print_3d_array2(char **A, int argc, char **argv)
{
	int	i;
	int	j;
	int	k;
	int	n;

	k = 0;
	while (argv[argc - 1][k] != '\0')
		k++;
	n = k / 3;
	if (k % 3 != 0)
		n++;
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < 3)
		{
			write(1, &A[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

void	print_3d_array(char ***A, int *paramMtrx)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < paramMtrx[1])
	{
		j = 0;
		while (j < 2)
		{
			k = 0;
			while (k < paramMtrx[2])
			{
				write(1, &A[i][j][k], 1);
				k++;
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	deallocate_memory(char ***A, int *paramMtrx)
{
	int	i;
	int	j;

	i = 0;
	while (i < paramMtrx[0])
	{
		j = 0;
		while (j < paramMtrx[0])
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

int	deallocate_memory2(char **arg, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(arg[i]);
	}
	free(arg);
	return (0);
}
