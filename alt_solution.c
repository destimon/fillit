/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alt_solution.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 18:04:20 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/12 19:18:25 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

/*
** size + 1 here because I need to have NULL-pointer at the end of the matrix
** and '\0' character at the end of every row;
**
** Also, I think here can be a memory leak.
*/

char			**matrix_realloc(char **matrix, size_t size)
{
	int		i;
	char	**copy;

	i = 0;
	copy = (char **)ft_memalloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		copy[i] = (char *)ft_memalloc(sizeof(char) * (size + 1));
		if (matrix[i])
		{
			ft_memcpy(copy, matrix, size + 1);
			free(matrix[i]);
		}
		i++;
	}
	free(matrix);
	return (copy);
}

static int		try_piece(char **matrix, t_figure *figure, int x, int y)
{
	t_el	*scheme;

	scheme = figure->scheme;
	while (scheme)
	{
		if (matrix[scheme->y + y][scheme->x + x] == '#')
			return (1);
		scheme = scheme->next;
	}
	return (0);
}

/*
**
*/

int		solve(t_figure *list, char **matrix)
{

	return (SUCCESS);
}