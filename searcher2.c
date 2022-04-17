/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searcher2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalan-g <agalan-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:49:16 by agalan-g          #+#    #+#             */
/*   Updated: 2022/04/17 18:58:45 by jposada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int search1(char ***A, int *paramMtrx, int pos, char *numtosearch)
{
	int	i =0;
	int	x =0;

		cont[3] = 0;// esto es x
	while (cont[3] <= paramMtrx[1])
	{
		cont[5] = 0; // esto es z
		while (cont[5] <= paramMtrx[2])
		{
			if (argv[cont[0]][cont[1]] == A[cont[3]][0][cont[5]])
			{
				write (1, &A[cont[3]][0][cont[5]], 1);
				return (0);
			}
			cont[5] = cont[5]; //aumentamos z
		}
		cont[3] = cont[3] + 1; // aumentamos i
	}
	return (0);
}
