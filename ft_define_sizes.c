/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_define_sizes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 12:56:22 by dcherend          #+#    #+#             */
/*   Updated: 2018/04/13 17:05:39 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	size_t	ft_vector_length_x(t_figure *fig)
{
	t_el		*elem;
	size_t		maxX;
	size_t		minX;
	size_t		i;

	i = 0;
	maxX = 0;
	minX = 0;
	elem = fig->scheme;
	while (elem)
	{
		if (maxX < elem->x)
			maxX = elem->x;
		if (minX > elem->x)
			minX = elem->x;
		elem = elem->next;
	}
	while (minX <= maxX)
	{
		minX++;
		i++;
	}
	return (i);
}

static	size_t	ft_vector_length_y(t_figure *fig)
{
	t_el	*elem;
	size_t	maxY;
	size_t	minY;
	size_t	i;

	i = 0;
	maxY = 0;
	minY = 0;
	elem = fig->scheme;
	while (elem)
	{
		if (maxY < elem->y)
		{
			maxY = elem->y;
		}
		if (minY > elem->y)
			minY = elem->y;
		elem = elem->next;
	}
	while (minY <= maxY)
	{
		minY++;
		i++;
	}
	return (i);
}

void			ft_define_sizes(t_figure *fig)
{
	while (fig)
	{
		fig->width = ft_vector_length_x(fig);
		fig->height = ft_vector_length_y(fig);
		fig = fig->next;
	}
}
