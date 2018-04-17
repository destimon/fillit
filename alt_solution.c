/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:04:20 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/17 19:36:32 by vtarasiu         ###   ########.fr       */
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
** Moves specified element to the beginning of the list and runs main function
*/

int			solve_from(t_figure *list, t_field *matrix, int index)
{
	t_figure	*copy;
	t_figure	*last;

	if (list == NULL)
		return (-1);
	copy = list;
	last = NULL;
	while (copy)
	{
		if (index-- == 0 && last != NULL)
		{
			last->next = copy->next;
			copy->next = list;
			list = copy;
			break ;
		}
		if (last == NULL)
			last = copy;
		copy = copy->next;
	}
	return (solve(list, matrix));
}

/*
** This solution is real. --ish.
*/

int				solve(t_figure *list, t_field *matrix)
{
	int			i;
	int			j;
	int			status;
	t_figure	*copy;

	copy = list;
	i = -1;
	status = 1;
	while (list)
	{
		while (++i < matrix->size && status)
		{
			j = -1;
			while (++j < matrix->size)
			{
				if (list->is_used == 0 && try_piece(matrix, list, j, i))
				{
					write_piece(matrix, list, j, i);
					list->is_used = 1;
					println_matrix(matrix);
					if (solve(copy->next, matrix) == 0)
					{
						status = 0;
						break ;
					}
				}
				//else if (list->is_used == 1)
				//	return (SUCCESS);
			}
		}
		list = list->next;
	}
	if(are_all_used(copy))
		return (SUCCESS);
	//if (list == NULL)
	//	return (1);
	//else

}
