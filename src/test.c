/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:23:12 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/21 18:42:57 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

int		main(int argc, char **argv)
{
	int			initial_size;
	t_figure	*figures;
	t_field		*field;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file");
		return (1);
	}
	initial_size = 2;
	figures = assign_letters(read_figures(argv[1]));
	field = init_field(initial_size);
	while (backtrace(field, figures))
		field = matrix_realloc(field, ++initial_size);
	if (field->size >= 2 && list_size(figures) > 0 && figures->scheme != NULL)
		println_matrix(field);
	else
		throw_error("No figures.");
	clear_figures(figures);
	clear_field(field);
	return (0);
}
