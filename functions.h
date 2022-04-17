/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jposada- <jposada-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:55:38 by jposada-          #+#    #+#             */
/*   Updated: 2022/04/17 22:07:15 by jposada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_fileSize (char *filename);
int ft_countlines (char *filename);
int ft_maxchar (int currentpos, int posstop,char *filename);
int	ft_checkfile (char *filename);
int paramMatrix (int *paramMtrx , char *filename);


int err_mem1(char*** A);
int err_mem2(char** A);
int err_mem3(char* A);
char	***declare(int *paramMtrx, char *filename);

int	ft_char_is_numeric(char str);
int	ft_str_is_printable(char str);

void	print_error(void);
int	is_number(char	*argv);
int	checkfile(char	*argv);
int	check_num_args(int argc, char **argv);
char *dictionaryused(int argc, char **argv);

void  print_3d_array2(char **A, int argc, char **argv);
void  print_3d_array(char ***A, int *paramMtrx);
int deallocate_memory(char ***A, int *paramMtrx);
int deallocate_memory2(char **arg, int n);
void	assign_values2(char ***A, int *paramMtrx, int *ijk, char *filename);
void  assign_values(char ***A, int *paramMtrx, char *filename);

int		ft_char_is_numeric(char str);
int		ft_char_is_printable(char str);
void	ft_getcharnumber(char ***matrix3d, char *text_line, int line);
void	ft_getvalues(char ***matrix3d, char *text_line, int line);
void	ft_put_lines_values_in_matrix(char ***matrix3d, char *text_line);

int	search1(char ***A, int *paramMtrx, int *cont, char **argv);
int	length_check(int argc, char **argv);
void	searcher(char ***A, int *paramMtrx, int argc, char **argv);

