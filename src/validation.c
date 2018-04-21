/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:54:31 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/21 18:33:07 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

static int	check_sides(const char **fld, int x, int y)
{
	if (x == 0 && y > 0 && y < 3 && (fld[y + 1][x] == '#' ||
		fld[y][x + 1] == '#' || fld[y - 1][x] == '#'))
		return (0);
	else if (y == 0 && x > 0 && x < 3 &&
		(fld[y][x + 1] == '#' || fld[y + 1][x] == '#' || fld[y][x - 1] == '#'))
		return (0);
	else if (x == 3 && y > 0 && y < 3 &&
		(fld[y][x - 1] == '#' || fld[y + 1][x] == '#' || fld[y - 1][x] == '#'))
		return (0);
	else if (y == 3 && x > 0 && x < 3 &&
		(fld[y][x - 1] == '#' || fld[y - 1][x] == '#' || fld[y][x + 1] == '#'))
		return (0);
	else
		return (1);
}

static int	check_corners(const char **fld, int x, int y)
{
	if (x == 0 && y == 0 && (fld[y + 1][x] == '#' || fld[y][x + 1] == '#'))
		return (0);
	else if (x == 0 && y == 3 && (fld[y][x + 1] == '#' || fld[y - 1][x] == '#'))
		return (0);
	else if (x == 3 && y == 0 && (fld[y][x - 1] == '#' || fld[y + 1][x] == '#'))
		return (0);
	else if (x == 3 && y == 3 && (fld[y][x - 1] == '#' || fld[y - 1][x] == '#'))
		return (0);
	else
		return (2);
}

static int	check_inside(const char **fld, int x, int y)
{
	if (!(x < 3 && y < 3 && x > 0 && y > 0 &&
			(fld[y + 1][x] == '#' || fld[y - 1][x] == '#' ||
			fld[y][x + 1] == '#' || fld[y][x - 1] == '#')))
		return (4);
	return (0);
}

/*
** vb for 'validate buffer'
*/

char		*vb(char *buffer, int size)
{
	if (size == 21 && buffer[20] != '\n')
		throw_error("Invalid data format.");
	if (size == 20 && buffer[19] != '\n')
		throw_error("Invalid data format.");
	return (buffer);
}

void		validate_neighbours(const char **fld, int x, int y)
{
	int		score;

	if ((fld[y][x] != '.' && fld[y][x] != '\n' && fld[y][x] != '#'))
		throw_error("Invalid character in buffer.");
	if (x == 4 && fld[y][x] != '\n')
		throw_error("No newline.");
	if (fld[y][x] == '.')
		return ;
	score = check_corners(fld, x, y) + check_sides(fld, x, y) +
			check_inside(fld, x, y);
	if (score == 7)
		throw_error("Some point has no valid neighbours.");
}
