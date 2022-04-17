/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_error_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlozano- <nlozano-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:21:54 by nlozano-          #+#    #+#             */
/*   Updated: 2022/04/17 21:55:00 by jposada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	print_error(void)
{
	write(2, "Error\n", 6);
}

int	is_number(char	*argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
	{
		if (argv[i] >= 48 && argv[i] <= 57)
			i++;
		else
			return (0);
	}
	return (1);
}

int	checkfile(char	*argv)
{
	int		fd;
	char	buf[1];
	char	*filename;

	filename = &argv[0];
	fd = open (filename, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (0);
	}
	else
	{
		if (read(fd, buf, 1) == 0)
		{
			close(fd);
			return (0);
		}
		close(fd);
		return (1);
	}
}

int	check_num_args(int argc, char **argv)
{
	if (argc <= 3 || argc == 1)
	{
		if (argc == 2)
		{
			if (is_number(argv[1]) != 1)
			{
				print_error();
			}		
			return (1);
		}
		if (argc == 3)
		{
			if (is_number(argv[2]) != 1)
			{
				print_error();
				return(0);
			}
			if (checkfile(argv[1]) != 1)
			{
				print_error();
				return(0);
			}
			return(1);
		}
	}
	return (0);
}

char *dictionaryused(int argc, char **argv)
{
	if (argc == 3)
		return (argv[1]);
	return("numbers.dict");
}
