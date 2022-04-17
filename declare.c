/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalan-g <agalan-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 04:47:36 by agalan-g          #+#    #+#             */
/*   Updated: 2022/04/17 22:44:05 by nlozano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "functions.h"

int	err_mem1(char ***A)
{
	if (A == NULL)
	{
		write(1, "Error, no hay espacio en memoria\n", 33);
		return (1);
	}
	return (0);
}

int	err_mem2(char **A)
{
	if (A == NULL)
	{
		write(1, "Error, no hay espacio en memoria\n", 33);
		return (1);
	}
	return (0);
}

int	err_mem3(char *A)
{
	if (A == NULL)
	{
		write(1, "Error, no hay espacio en memoria\n", 33);
		return (1);
	}
	return (0);
}

char	***declare(int *param_mtrx, char *filename)
{
	int		i;
	int		j;
	char	***a;

	a = (char ***)malloc(param_mtrx[0] * sizeof(char **));
	if (err_mem1(A) == 1)
		return (A);
	i = 0;
	while (i < paramMtrx[0])
	{
		A[i] = (char **)malloc(param_mtrx[0] * sizeof(char *));
		if (err_mem2(A[i]) == 1)
			return (A);
		j = 0;
		while (j < param_mtrx[0])
		{
			A[i][j] = (char *)malloc((param_mtrx[0] * 2) * sizeof(char));
			if (err_mem3(A[i][j]) == 1)
				return (A);
			j++;
		}
		i++;
	}
	assign_values(A, param_mtrx, filename);
	return (A);
}
