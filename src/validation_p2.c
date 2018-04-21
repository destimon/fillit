/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_p2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 18:33:11 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/21 18:34:02 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void		find_connections(t_figure *figure)
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
		while (elements)
		{
			x = iter->x - elements->x;
			y = iter->y - elements->y;
			if (ABS(x) + ABS(y) < 2)
				c++;
			elements = elements->next;
		}
		iter = iter->next;
	}
	if (c != 10 && c != 12)
		throw_error("Some point is disconnected from other.");
}

t_figure	*val_fig(t_figure *figure)
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
