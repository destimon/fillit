/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:21:20 by dcherend          #+#    #+#             */
/*   Updated: 2018/04/05 19:49:39 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**expand_matrix(char **matrix, int len, int x, int y)
{
	int		i;
	int		tmp;

	if (x >= len)
		tmp = x;
	else
		tmp = y;
	i = 0;
	matrix = realloc(matrix, tmp);
	while (i < len)
	{
		matrix[i] = realloc(matrix[i], tmp);
		ft_memset(matrix[i], '.', tmp);
		matrix[i][tmp] = '\0';
		i++;
	}
	while (i < tmp)
	{
		matrix[i] = ft_memalloc(tmp);
		ft_memset(matrix[i], '.', tmp);
		i++;
	}
	return (matrix);
}

void	ft_fill_matrix(char **matrix, t_figure *fig)
{
	int		i;
	int		j;
	int		len;
	t_el	*tmp;

	len = 4;
	tmp = fig->scheme;
	while (tmp)
	{
		i = 0;
		if (tmp->x >= len || tmp->y >= len)
		{
			matrix = expand_matrix(matrix, len, tmp->x, tmp->y);
			if (tmp->x > len)
				len += tmp->x;
			else if (tmp->y > len)
				len += tmp->y;
		}
		while (i < len)
		{
			j = 0;
			while (j < len)
			{
				if ((i == tmp->x) && (j == tmp->y))
					matrix[i][j] = 'A';
				j++;
			}
			i++;
		}
		tmp = tmp->next;
	}
}
