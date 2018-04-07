/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:58:58 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/07 13:55:45 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_el	append_el(t_figure *figure, int x, int y, const t_el pivot)
{
	t_el	*copy;

	if (figure->scheme == NULL)
	{
		figure->scheme = ft_create_el(0, 0);
	}
	else
	{
		copy = figure->scheme->next;
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
