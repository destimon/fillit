/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:58:58 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/05 19:37:47 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_el	*append_el(t_figure *figure, int x, int y, t_el *pivot)
{
	t_el	*copy;
	int 	i;

	if (figure->scheme == NULL)
	{
		figure->scheme = ft_create_el(0, 0);
		return (figure->scheme);
	}
	else
	{
		copy = figure->scheme;
		i = 0;
		while (copy && copy->next)
		{
			i++;
			copy = copy->next;
		}
		if (i > 4)
			throw_error("Attempt to add 5th point.");
		copy->next = ft_create_el(pivot->x - x, pivot->y - y);
		return (figure->scheme);
	}
}

t_figure	*construct_figure()
{
	t_figure	*new;

	new = (t_figure*)malloc(sizeof(t_figure));
	if (new)
	{
		new->scheme = NULL;
		new->next = NULL;
	}
	else
		throw_error("Figure malloc failed.");
	return (new);
}