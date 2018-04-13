/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_scheme.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <dcherend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:09:30 by dcherend          #+#    #+#             */
/*   Updated: 2018/04/13 19:12:59 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "libft/libft.h"
#include "fillit.h"

void	ft_print_scheme(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		ft_putendl(matrix[i]);
		i++;
	}
}

void	print_figure(t_figure *figure, int x, int y)
{
	char	fig[5][7];
	int		i;

	i = 0;
	while (i < 5)
		ft_memset(fig[i++], '\0', 7);
	i = 0;
	while (i < 5)
		ft_memset(fig[i++], '.', 5);
	i = 0;
	while (i < 5)
		fig[i++][5] = '\n';
	while (figure->scheme)
	{
		fig[y + figure->scheme->y][x + figure->scheme->x] = 'A';
		figure->scheme = figure->scheme->next;
	}
	i = 0;
	while (i < 5)
		printf("%s", fig[i++]);
}
