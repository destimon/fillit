/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:58:58 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/17 17:11:08 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
			throw_error("Attempt to add 5th point.");
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

t_figure	*set_unused(t_figure *list)
{
	t_figure	*copy;

	copy = list;
	while (copy)
	{
		copy->is_used = 0;
		copy = copy->next;
	}
	return (list);
}

int			are_all_used(t_figure *list)
{
	t_figure	*copy;

	copy = list;
	while (copy)
	{
		if(copy->is_used == 0)
			return (0);
		copy = copy->next;
	}
	return (1);
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
		throw_error("Figure malloc failed.");
	return (new);
}
