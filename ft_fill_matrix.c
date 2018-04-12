/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:21:20 by dcherend          #+#    #+#             */
/*   Updated: 2018/04/10 15:31:25 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_get_maximum_x(t_figure *fig)
{
	t_el	*elem;
	int	res;

	res = 0;
	el = fig->scheme;
	while (el)
	{
		if (elem->x > res)
			res = elem->x;
	}
	return (res);
}

static	int		ft_get_maximum_y(t_figure *fig)
{
	t_el	*elem;
	int	res;

	res = 0;
	el = fig->scheme;
	while (el)
	{
		if (elem->y > res)
			res = elem->y;
	}
	return (res);
}

static	char		ft_try_put(t_figure *fig, char **matrix, int x_l, int y_l
				int x, int y, int size)
{ 
	while (x <= size)
	{
		while (y <= size)
		{
			if ((size - x >= x_l) && (size - y >= y_l))
			{
				ft_put_figure(fig, matrix, x, y);
				return (1);
			}
			y++;
		}
		x++;
	}
	return (0);
}

static	char		**ft_put_figure(t_figure fig, char **matrix, int x, int y
				char letter)
{
	while (x <= size)
	{
		while (y <= size)
		{
			matrix[x][y] = letter;
			y++;
		}
		x++;
	}
}

static	char		**ft_init_matrix(t_figure *fig, char **matrix, int x_l, 
				int y_l, int size, char letter)
{
	int	x;
	int	y;
	int	check;

	check = 0;
	while (x <= size)
	{
		while (y <= size)
		{
			if (ft_try_put(fig, matrix, x_l, y_l, x, y, size, letter))
				check = 1;
			y++;
		}
		x++;
	}
	if (check == 0)
	{
		matrix = ft_expand_matrix();
		ft_init_matrix(fig, matrix, x_l, y_l, size + 1);
	}
	return (matrix);
}

static	char		**reinit_matrix(t_figure *fig, int size)
{
	
}

char			**ft_fill_matrix(char **matrix, t_figure *fig)
{
	int	size;
	int	x_length;
	int	y_length;
	char	letter;

	letter = 'A';
	size = 2;
	while (fig)
	{
		x_length = ft_get_maximum_x(fig);
		y_length = ft_get_maximum_y(fig);
		ft_init_matrix(fig, matrix, x_l, y_l, size, letter);
		letter++;
		fig = fig->next;
	}
	return (matrix);
}
