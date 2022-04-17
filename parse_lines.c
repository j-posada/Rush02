/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jposada- <jposada-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 12:30:02 by jposada-          #+#    #+#             */
/*   Updated: 2022/04/17 22:58:19 by jposada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "functions.h"

int		ft_char_is_numeric(char str);
int		ft_char_is_printable(char str);
void	ft_getcharnumber(char ***matrix3d, char *text_line, int line);
void	ft_getvalues(char ***matrix3d, char *text_line, int line);

void	ft_put_lines_values_in_matrix(char ***matrix3d, char *text_line)
{
	int	pos_ini;
	int	pos_end;
	int	line;

	pos_ini = 0;
	pos_end = 0;
	line = 0;
	ft_getcharnumber(matrix3d, text_line, line);
	ft_getvalues(matrix3d, text_line, line);
	line++;
}

void	ft_getcharnumber(char ***matrix3d, char *text_line, int line)
{
	int	pos;

	pos = 0;
	while (text_line[pos] != '\n' || text_line[pos] != '\0')
	{
		while (ft_char_is_numeric(text_line[pos]) == 1)
		{
			matrix3d[line][0][pos] = text_line[pos];
			pos++;
		}
	}
}

void	ft_getvalues(char ***matrix3d, char *text_line, int line)
{
	int	pos_current;
	int	pos_ini;
	int	pos_end;
	int	i;

	pos_ini = 0;
	pos_end = 0;
	pos_current = 0;
	i = 0;
	while (text_line[pos_current] != ':' || text_line[pos_current] != '\0')
		pos_current++;
	while (ft_char_is_printable(text_line[pos_current]) == 0
		&& text_line[pos_current] != ' ' )
		pos_current++;
	pos_ini = pos_current;
	while (ft_char_is_printable(text_line[pos_current]) == 1)
		if (text_line[pos_current] != ' ')
			pos_end = pos_current;
	while (i < (pos_end - pos_ini))
	{
		matrix3d[line][1][i] = text_line[pos_ini];
		pos_ini++;
		i++;
	}
}
