/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:21:20 by dcherend          #+#    #+#             */
/*   Updated: 2018/04/07 16:32:54 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		define_length(int x, int y)
{
	int	res;

	res = 0;
	if (x > y)
		res = x;
	else
		res = y;
	return (res);
}

int		ft_get_maximum(t_figure *fig)
{
	t_el 	*element;
	int		res;

	res = 0;
	element = fig->scheme;
	while (element)
	{
		if (element->x > element->y && element->x > res)
			res = element->x;
		else if (element->y > res)
			res = element->y;
		element = element->next;
	}
	return (res + 1);
}

static	char	**init_matrix(t_figure *fig)
{
	char	**mat;
	int		size;
	int		i;

	i = 0;
	size = ft_get_maximum(fig);
	mat = ft_memalloc(size + 1);
	while (i < size)
	{
		mat[i] = ft_memalloc(size + 1);
		ft_memset(mat[i], '.', size);
		i++;
	}
	mat[i] = NULL;
	return (mat);
}

char	**ft_fill_matrix(char **matrix, t_figure *fig)
{
	while (fig)
	{
		matrix = init_matrix(fig);
		fig = fig->next;
	}
	return (matrix);
}
