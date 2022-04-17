/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jposada- <jposada-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:58:07 by jposada-          #+#    #+#             */
/*   Updated: 2022/04/17 22:07:46 by jposada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "functions.h"

int main (int argc, char *argv[])
{
	int paramMtrx[3];
	int err;
	char	***A;
	
	if (check_num_args(argc, argv) !=1)
	{
		return(0);
	}
	err = paramMatrix(paramMtrx, dictionaryused(argc,argv));
	if (err == 1)
		return (0);
	A = declare(paramMtrx,dictionaryused(argc,argv));
	print_3d_array(A, paramMtrx);
//	searcher(A, paramMtrx, argc, argv);
	printf("PRUEBA2 PASADA \n");
	err=deallocate_memory(A, paramMtrx);

	printf("Numero a buscar: %s\n", argv[1]);
return (0);
}


