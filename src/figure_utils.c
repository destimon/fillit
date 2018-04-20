/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:58:58 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/20 17:40:31 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_el		*append_el(t_figure *figure, int x, int y, t_el *pivot)
{
	t_el	*copy;
	int		i;

	if (figure->scheme == NULL)
	{
		figure->scheme = ft_create_el(0, 0);
		return (figure->scheme);
	}
	else
	{
		copy = figure->scheme;
		i = 1;
		while (copy && copy->next)
		{
			i++;
			copy = copy->next;
		}
		if (i + 1 > 4)
			throw_error("Attempt to add 5th element");
		copy->next = ft_create_el(x - pivot->x, y - pivot->y);
		return (figure->scheme);
	}
}

t_figure	*assign_letters(t_figure *list)
{
	char		letter;
	t_figure	*copy;

	letter = 'A';
	copy = list;
	while (copy)
	{
		copy->letter = letter++;
		copy = copy->next;
	}
	return (list);
}

int			list_size(t_figure *list)
{
	int			i;
	t_figure	*copy;

	i = 0;
	copy = list;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_figure	*ft_create_figure_empty(void)
{
	t_figure	*new;

	new = (t_figure*)malloc(sizeof(t_figure));
	if (new)
	{
		new->scheme = NULL;
		new->next = NULL;
	}
	else
		throw_error("Malloc failed.");
	return (new);
}
