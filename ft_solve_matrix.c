/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 15:52:08 by dcherend          #+#    #+#             */
/*   Updated: 2018/04/10 15:14:44 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**fill_field(char **field, t_figure *fig, char letter)
{
	int		x;
	int		y;
	int		len;
	t_el	*elem;

	len = ft_strlen(*field);
	elem = fig->scheme;
	while (elem)
	{
		x = 0;
		while (x < len)
		{
			y = 0;
			while (y < len)
			{
				if (x == elem->x && y == elem->y)
				{
					field[x][y] = letter;
				}
				y++;
			}
			x++;
		}
		elem = elem->next;
	}
	return (field);
}

char	**ft_solve_matrix(char **field, t_figure *fig)
{
	char	letter;

	align = 0;
	letter = 'A';
	while (fig)
	{
		field = fill_field(field, fig, letter);
		letter++;
		fig = fig->next;
	}
	return (field);
}
