/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 13:55:38 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/21 14:05:10 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

void		clear_figures(t_figure *list)
{
	t_el		*el;
	t_el		*swap;
	t_figure	*temp;

	while (list)
	{
		el = list->scheme;
		while (el)
		{
			swap = el->next;
			free(el);
			el = swap;
		}
		temp = list->next;
		free(list);
		list = temp;
	}
}

void		clear_field(t_field *field)
{
	int		i;

	i = 0;
	while (i < field->size)
		free(field->field[i++]);
	free(field);
}
