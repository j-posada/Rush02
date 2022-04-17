/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jposada- <jposada-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:13:52 by jposada-          #+#    #+#             */
/*   Updated: 2022/04/17 21:40:13 by jposada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include "functions.h"

int ft_fileSize (char *filename)
{
	int	fd;
	char	buf[1];
	ssize_t	nr_bytes;
	int	sizefile;

	sizefile = 0;
	nr_bytes = -1;
	fd = open (filename,O_RDONLY);
	while ((int)(nr_bytes) != 0)
	{
		nr_bytes = read (fd, buf,1);
		sizefile++;
	}
	close(fd);
	return(sizefile);
}

int ft_countlines (char *filename)
{
	char	buf[1];
	int	fd;
	ssize_t	nr_bytes;
	int	eolcount;

	eolcount = 0;
	nr_bytes = -1;
	fd = open (filename,O_RDONLY);
	while ((int)(nr_bytes) != 0)
	{
		nr_bytes = read (fd, buf,1);
		if (buf[0] == '\n' )
			eolcount++;
	}
	close(fd);
	return(eolcount);
}

int ft_maxchar (int currentpos, int posstop, char *filename)
{
	int	fd;
	char	buf[1];
	ssize_t	nr_bytes;
	int	gap;
	int size_max;

	nr_bytes = -1;
	size_max = 0;
	fd = open (filename,O_RDONLY);
	while ((int)(nr_bytes) != 0)
	{
		nr_bytes = read (fd, buf,1);
		if (buf[0] == ':' || buf[0] == '\n')
		{
			gap = currentpos - posstop;
			if (gap > size_max)
				size_max = gap;
			posstop = currentpos;
		}
		currentpos++;
	}
	close(fd);
	return(size_max);
}

int	ft_checkfile (char *filename)
{
	int	fd;
	char	buf[1];

	fd = open (filename,O_RDONLY);
	if (fd == -1)
	{
		print_error();
		close(fd);
		return (1);
	}
	else
	{
		if (read(fd,buf,1) == 0)
		{
			print_error();
			close(fd);
			return (1);
		}
		close(fd);
		return (0);
	}
}

int paramMatrix (int *paramMtrx, char *filename)
{
	int	currentpos;
	int err;
	int	posstop;

	currentpos = 0;
	posstop = 0;
	err = ft_checkfile(filename);
	if (err == 0)
	{
		paramMtrx[0] = ft_fileSize(filename);
		paramMtrx[1] = ft_countlines(filename);
		paramMtrx[2] = ft_maxchar(currentpos, posstop, filename);
	}
	return (err);
}

