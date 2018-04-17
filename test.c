/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:23:12 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/17 19:36:32 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "fillit.h"

int		main(int argc, char **argv)
{
	size_t		initial_size;
	t_figure	*figures;
	t_field		*field;
	int			i;
	char		**matrix;

	if (argc != 2)
		return (1);
	i = 0;
	initial_size = 2;
	figures = assign_letters(read_figures(argv[1]));
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
	/*
	 * TODO: add another loop that tries all figures and finds smallest square.
	 *
	 * Maybe, should calculate smallest possible area from number of
	 * figures or just store somewhere matrix.
	 *
	 * And don't forget to clear memory.
	 */
	i = 0;
	while (i < list_size(g_figure_list))
	{
		while (solve_from(set_unused(figures), field, i))
			field = matrix_realloc(field, ++initial_size);
		i++;
	}
	println_matrix(field);
	printf("\nSuccess!\nSize of matrix: %zu\n", field->size);
	return (0);
}
