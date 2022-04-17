/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agalan-g <agalan-g@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 04:41:18 by agalan-g          #+#    #+#             */
/*   Updated: 2022/04/17 16:22:47 by agalan-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	paramMatrix(int *paramMtrx);
char	***declare(int *paramMtrx);
void	print_3d_array(char ***A, int *paramMtrx);
void	deallocate_memory(char ***A, int *paramMtrx);
void	searcher(char ***A, int *paramMtrx, int argc, char **argv);

int	main(int argc, char **argv)
{
	int paramMtrx[3];
	int err;
	char	***A;

	(void)argc;
	(void)argv;

	err = paramMatrix(paramMtrx);
	if (err == 1)
		return (0);
	A = declare(paramMtrx);
	print_3d_array(A, paramMtrx);
	searcher(A, paramMtrx, argc, argv);
	printf("PRUEBA2 PASADA \n");
	deallocate_memory(A, paramMtrx);
	return(0);
}
