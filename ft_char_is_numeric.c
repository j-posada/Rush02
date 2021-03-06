/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_is_numeric.c                                :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: jposada- <jposada-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:20:15 by jposada-          #+#    #+#             */
/*   Updated: 2022/04/17 13:57:17 by jposada-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_numeric(char str)
{
	if ((str < '0') || (str > '9'))
		return (0);
	return (1);
}
