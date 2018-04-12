/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:21:20 by dcherend          #+#    #+#             */
/*   Updated: 2018/04/12 15:57:44 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char		**ft_try_put(t_figure *fig, char **matrix, int i, int j,
					int *size)
{
	char	**mat;

	mat = matrix;
	while (i < fig->width)
	{
		while (j < fig->height)
		{
			if (mat[i][j] == '.' && (*size - i) == fig->width &&
					(*size - j) == fig->height)
				return (matrix);
			if (mat[i][j] != '.' && (*size - i) == fig->width &&
					(*size - j) == fig->height)
				mat[i][j] = fig->letter;
			j++;
		}
		i++;
	}
	return (mat);
}

static	char		**ft_init_matrix(t_figure *fig, char **matrix, int *size)
{
	size_t		i;
	size_t		j;

	while (i <= *size)
	{
		while (j <= *size)
		{
			if (matrix[i][j] != '.' && (fig->width >= (size - i) &&
						fig->height >= (size - j)))
				matrix = ft_try_put(fig, matrix, i, j, size);
			j++;
		}
		i++;
	}
}

char			**ft_fill_matrix(char **matrix, t_figure *fig)
{
	char	letter;
	int		*size;
	
	*size = 2;
	letter = 'A';
	while (fig)
	{
		fig->letter = letter;
		ft_init_matrix(fig, matrix, size);
		fig = fig->next;
		letter++;
	}
	return (matrix);
}
