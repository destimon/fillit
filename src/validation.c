/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:54:31 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/21 15:27:04 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
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

static void	find_connections(t_figure *figure)
{
	int		c;
	int		x;
	int		y;
	t_el	*elements;
	t_el	*iter;

	c = 0;
	iter = figure->scheme;
	while (iter)
	{
		elements = figure->scheme;
		while (elements->next)
		{
			x = ABS(elements->next->x) - ABS(elements->x);
			y = ABS(elements->next->y) - ABS(elements->y);
			if (!(x >= 1 && y >= 1))
				c++;
			elements = elements->next;
		}
		iter = iter->next;
	}
	if (c != 12 && c != 8)
	{
		//printf("Connections: %d\n", c);
		throw_error("Some point is disconnected from other.");
	}
}

t_figure	*validate_figure(t_figure *figure)
{
	int		points;
	t_el	*copy;

	points = 0;
	copy = figure->scheme;
	if (copy == NULL)
		return (figure);
	find_connections(figure);
	while (copy)
	{
		copy = copy->next;
		points++;
	}
	if (points != 4)
		throw_error("Less than 4 points in figure.");
	return (figure);
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
