/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalan-g <agalan-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 13:08:08 by agalan-g          #+#    #+#             */
/*   Updated: 2022/04/17 16:24:42 by agalan-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	search1(char ***A, int *paramMtrx, int *cont, char **argv);

int	length_check(int argc, char **argv)
{
	int i;

	i = 0;
	while (argv[argc - 1][i] != '\0')
		i++;
	if ((i % 3) != 0)
	{
		if ((i % 3) == 2)
			return (2);
		else
			return (3);
	}
	return (0);

}

void	searcher(char ***A, int *paramMtrx, int argc, char **argv)
{
	int cont[6];

	printf("PRUEBA1 PASADA\n");
	cont[0] = argc - 1; // esto es argc
	cont[1] = 1; // esto es i
	cont[2] = length_check(cont[0], argv); //esto es pos3
	while(argv[cont[0]][cont[1]] != '\0')
	{
		printf("HOLA");
		if (argv[cont[0]][cont[1]] != '0')
		{
			if (cont[2] == 1)
			{
				search1(A, paramMtrx, cont, argv);
				//puthund --> deberia poner el hundred siempre.
			}
			if(cont[2] == 2)
				if(argv[cont[0]][cont[1]] == '1')
				{
					//searchnum3 --> deberia buscar del 10 - 19
					cont[1] = cont[1] + 1;
				}
				//else
				//{
					//searchnum2 --> deberia buscar el 20, 30, 40...
				//}
			if (cont[2] == 3)
			{
				search1(A, paramMtrx, cont, argv);
				//searchdivi --> deberia buscar los divisores.
			}
		}
		cont[1] = cont[1] + 1;
	}
}
