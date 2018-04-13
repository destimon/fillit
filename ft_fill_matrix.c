/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <dcherend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:21:20 by dcherend          #+#    #+#             */
/*   Updated: 2018/04/13 19:54:52 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	char		**ft_expand_matrix(char **matrix)
{
	char	**newmat;
	int 	i;

	i = 0;
	g_size++; /* Increase size of matrix */
	newmat = realloc(matrix, g_size + 1); /* Y expand */
	while (matrix[i])
	{
		newmat[i] = realloc(matrix[i], g_size + 1); /* X expand */
		i++;
	}
	while (i < g_size) /* Unallocated space to prevent error */
	{
		newmat[i] = ft_memalloc(g_size + 1);
		i++;
	}
	return (newmat);
}

static	void		ft_try_put(t_el *el, char **matrix, int i, int j,
						char letter)
{
	/* Check for free space */
	if (matrix[i][j] == '.' && el->x == i && el->y == j)
		matrix[i][j] = letter;
	else
	{
		if (i + 1 > g_size) /* X pos bypassed */
		{
			printf("Huy\n");
			if (j + 1 > g_size) /* Y pos bypassed */
			{
				matrix = ft_expand_matrix(matrix); /* So we'll expand */
				ft_try_put(el, matrix, i, j, letter);	/* And try again */
			}
			else /* Y move */
			{
				ft_try_put(el, matrix, i, j + 1, letter);
			}
		}
		else /* X move */
			ft_try_put(el, matrix, i + 1, j, letter);
	} 
}

static	void	**ft_enter_figure(t_figure *fig, char **matrix)
{
	t_el	*el;
	int 	i;
	int 	j;

	el = fig->scheme;
	/* Walk on the element list */
	while (el)
	{
		i = 0;
		j = 0;
		/* Walk on the matrix */
		while (i < g_size)
		{
			while (j < g_size)
			{
				ft_try_put(el, matrix, i, j, fig->letter);
				j++;
			}
			i++;
		}
		el = el->next;
	}
}

char			**ft_fill_matrix(char **matrix, t_figure *fig)
{
	char	letter;
	int		i;

	i = 0;
	g_size = 2;
	letter = 'A';
	/* Init 2x2 matrix */
	matrix = ft_memalloc(g_size + 1);
	while (i < g_size)
	{
		matrix[i] = ft_memalloc(g_size + 1);
		ft_memset(matrix[i], '.', g_size);
		i++;
	}
	/* Iterate figures to matrix */
	while (fig)
	{
		fig->letter = letter;
		ft_enter_figure(fig, matrix);
		letter++;
		fig = fig->next;
	}
	return (matrix);
}
