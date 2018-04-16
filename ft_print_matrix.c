/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 14:17:43 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/16 14:58:28 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_matrix(t_field *matrix)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < matrix->size)
	{
		j = 0;
		while (j < matrix->size)
		{
			write(1, (matrix->field[i] + j), 1);
			j++;
		}
		if (i < matrix->size - 1)
			write(1, "\n", 1);
		i++;
	}
}

void		println_matrix(t_field *matrix)
{
	print_matrix(matrix);
	write(1, "\n", 1);
}

void		print_char_matrix(char **matrix)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			write(1, (matrix[i] + j), 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}