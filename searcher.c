/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalan-g <agalan-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:08:08 by agalan-g          #+#    #+#             */
/*   Updated: 2022/04/17 18:58:49 by jposada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	search1(char ***A, int *paramMtrx, char *numtosearch);

int	length_check(char *number)
{
	int i;

	i = 0;
	while (number[i] != '\0')
		i++;
	if ((i % 3) != 0)
	{
		if ((i % 3) == 2)
			return (2);
		else
			return (3);
	}
	return (1);
}

void	searcher(char ***A, int *paramMtrx, char *numtosearch)
{
	int cont[6];

	printf("PRUEBA1 PASADA\n");
	cont[0] = 1; // esto es argc
	cont[1] = 1; // esto es i
	cont[2] = length_check(numtosearch); //esto es pos3
	search1(A, paramMtrx, numtosearch);
	//puthund --> deberia poner el hundred siempre.

}
