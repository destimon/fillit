/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/21 13:55:38 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/21 14:14:30 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_field		*init_field(int initial_size)
{
	int			i;
	char		**matrix;
	t_field		*field;

	i = 0;
	field = (t_field *)malloc(sizeof(t_field));
	matrix = (char **)ft_memalloc(sizeof(char *) * (initial_size + 1));
	while (i < initial_size + 1)
	{
		matrix[i] = (char *)ft_memalloc(sizeof(char) * (initial_size + 1));
		ft_memset(matrix[i], '.', initial_size);
		i++;
	}
	field->field = matrix;
	field->size = initial_size;
	return (field);
}

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
