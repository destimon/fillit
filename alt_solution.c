/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:04:20 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/19 18:02:01 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "libft/libft.h"
#include "fillit.h"

/*
** @param size - desired size.
**
** size + 1 here because I need to have NULL-pointer at the end of the matrix
** and '\0' character at the end of every row just in case
**
** Also, I think here can be a memory leak.
*/

t_field			*matrix_realloc(t_field *matrix, size_t size)
{
	size_t		i;
	char		**copy;
	t_field		*mtrx;

	i = 0;
	mtrx = (t_field *)malloc(sizeof(t_field));
	mtrx->size = size;
	copy = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		copy[i] = (char *)ft_memalloc(sizeof(char) * (size + 1));
		ft_memset(copy[i], '.', size);
		free(matrix->field[i]);
		i++;
	}
	free(matrix);
	mtrx->field = copy;
	return (mtrx);
}

/*
** @return 0 if piece cannot be placed, 1 otherwise
*/

static int		try_piece(t_field *mtrx, t_figure *figure, int x, int y)
{
	t_el	*scheme;
	int		dx;
	int		dy;

	scheme = figure->scheme;
	while (scheme)
	{
		dx = scheme->x + x;
		dy = scheme->y + y;
		if (dx >= mtrx->size || dy >= mtrx->size)
			return (0);
		if (mtrx->field[dy][dx] != '.')
			return (0);
		scheme = scheme->next;
	}
	dy = -1;
	while (++dy < mtrx->size)
	{
		dx = -1;
		while (++dx < mtrx->size)
			if (mtrx->field[dy][dx] == figure->letter)
				return (0);
	}
	return (1);
}

static int		write_piece(t_field *matrix, t_figure *figure, int x, int y)
{
	t_el	*scheme;
	int		dx;
	int		dy;

	scheme = figure->scheme;
	while (scheme)
	{
		dx = scheme->x + x;
		dy = scheme->y + y;
		if (matrix->field[dy][dx] == '.')
			matrix->field[dy][dx] = figure->letter;
		else
		{
			print_matrix(matrix);
			throw_error("Attempt to write piece to cell with existing piece");
		}
		scheme = scheme->next;
	}
	return (1);
}

/*
** Removes piece by deleting all its letters.
*/

static t_figure	*remove_all_pieces(t_field *matrix, t_figure *figure)
{
	char	**field;
	int		i;
	int		j;

	while (figure)
	{
		field = matrix->field;
		i = 0;
		while (i < matrix->size)
		{
			j = 0;
			while (j < matrix->size)
			{
				if (field[i][j] == figure->letter)
					field[i][j] = '.';
				j++;
			}
			i++;
		}
		figure = figure->next;
	}
	return (figure);
}

int				backtrace(t_field *matrix, t_figure *list)
{
	int		x;
	int		y;

	if (list == NULL)
		return (0);
	y = -1;
	while (++y < matrix->size)
	{
		x = -1;
		while (++x < matrix->size)
		{
			if (try_piece(matrix, list, x, y))
			{
				write_piece(matrix, list, x, y);
				if (backtrace(matrix, list->next) != 0)
					remove_all_pieces(matrix, list);
				else
					return (0);
			}
		}
	}
	if (list_size(list) != 0)
		return (1);
	return (1);
}
