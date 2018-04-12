/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:54:31 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/12 16:26:22 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

t_figure	*validate_figure(const t_figure *figure)
{
	int		points;
	int		x;
	int		y;
	t_el	*copy;

	points = 1;
	copy = figure->scheme;
	while (copy->next)
	{
		x = ABS(copy->next->x) - ABS(copy->x);
		y = ABS(copy->next->y) - ABS(copy->y);
		if (x >= 1 && y >= 1)
			throw_error("Some points are disconnected from each other.");
		copy = copy->next;
		points++;
	}
	if (points != 4)
		throw_error("Less than 4 points in figure.");
	return ((t_figure *)figure);
}

void		validate_neighbours(const char **fld, int x, int y)
{
	int		score;

	if ((fld[y][x] != '.' && fld[y][x] != '\n' && fld[y][x] != '#'))
		throw_error("Invalid character in buffer.");
	if (fld[y][x] == '.')
		return ;
	score = check_corners(fld, x, y) + check_sides(fld, x, y) +
			check_inside(fld, x, y);
	if (score == 7)
		throw_error("Some point has no valid neighbours.");
}
