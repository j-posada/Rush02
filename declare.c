/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   declare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalan-g <agalan-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 04:47:36 by agalan-g          #+#    #+#             */
/*   Updated: 2022/04/17 11:13:00 by agalan-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	assign_values(char ***A, int *paramMtrx);

int err_mem1(char*** A)
{
	if (A == NULL)
    {
        write(1, "Error, no hay espacio en memoria\n", 33);
        return (1);
    }
	return (0);
}

int err_mem2(char** A)
{
	if (A == NULL)
    {
        write(1, "Error, no hay espacio en memoria\n", 33);
        return (1);
    }
	return (0);
}

int err_mem3(char* A)
{
	if (A == NULL)
	{
		write(1, "Error, no hay espacio en memoria\n", 33);
		return (1);
	}
	return (0);
}

char	***declare(int *paramMtrx)
{
	int i;
	int j;

	char*** A = (char***)malloc(paramMtrx[0] * sizeof(char**));
 	if (err_mem1(A) == 1)
		return (A);
	i = 0;
    while (i < paramMtrx[0])
    {
        A[i] = (char**)malloc(paramMtrx[0] * sizeof(char*));
        if (err_mem2(A[i]) == 1)
			return (A);
		j = 0;
        while (j < paramMtrx[0])
        {
            A[i][j] = (char*)malloc((paramMtrx[0] * 2)* sizeof(char));
            if (err_mem3(A[i][j]) == 1)
				return (A);
			j++;
        }
		i++;
    }
	assign_values(A, paramMtrx);
	return(A);
}
