/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:23:12 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/19 17:59:13 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int			initial_size;
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
	while (backtrace(field, figures))
		field = matrix_realloc(field, ++initial_size);
	println_matrix(field);
	return (0);
}
