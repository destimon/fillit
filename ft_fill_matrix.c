/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 14:21:20 by dcherend          #+#    #+#             */
/*   Updated: 2018/04/05 17:18:33 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	**expand_matrix(char **matrix, int len, int x, int y)
{
	int	i;
	int	tmp;

	i = 0;
	if (x > y)
		tmp = x;
	else
		tmp = y;
	matrix = realloc(matrix, tmp); /* write ft_realloc */
	if (
	while (len < tmp)
	{
		matrix[len] = (char*)malloc(sizeof(char) * tmp + 1);
		ft_memset(matrix[len], '.', tmp);
		matrix[len][tmp] = '\0';
		len++;
	}
	matrix[len] = NULL;
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
		if (tmp->x > len || tmp->y > len)
			matrix = expand_matrix(matrix, len, tmp->x, tmp->y);
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
