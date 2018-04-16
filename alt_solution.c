/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:04:20 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/16 13:11:31 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_field			*matrix_realloc(char **matrix, size_t size)
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
		if (matrix[i])
		{
			ft_memcpy(copy, matrix[i], size + 1);
			free(matrix[i]);
		}
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
		if (dx < mtrx->size && dy < mtrx->size && mtrx->field[dy][dx] == '#')
			return (0);
		scheme = scheme->next;
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
		if (matrix->field[dy][dx] > 'Z' || matrix->field[dy][dx] < 'A')
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
** Removes piece by passing all figure points and deleting all letters there.
*/

static int		remove_piece(t_field *matrix, t_figure *figure, int x, int y)
{
	t_el	*scheme;
	int		dx;
	int		dy;

	scheme = figure->scheme;
	while (scheme)
	{
		dx = scheme->x + x;
		dy = scheme->y + y;
		if (matrix->field[dy][dx] == figure->letter)
			matrix->field[dy][dx] = '.';
		else
		{
			print_matrix(matrix);
			throw_error("Attempt to remove wrong piece");
		}
		scheme = scheme->next;
	}
	return (1);
}

/*
** Removes piece by deleting all its letters.
*/

static int		remove_kebab(t_field *matrix, t_figure *figure, int x, int y)
{
	char	**field;
	int		i;
	int		j;

	i = 0;
	field = matrix->field;
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
	return (1);
}
/*
** hullo
*/

int				solve(t_figure *list, char **matrix)
{
	int i;

	return (SUCCESS);
}
