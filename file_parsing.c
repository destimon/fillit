/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:18:51 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/11 19:20:49 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "fillit.h"

t_figure	*create_figure(const char *field)
{
	int			y;
	int			x;
	char		**buf;
	t_el		*pivot;
	t_figure	*new;

	new = ft_create_figure_empty();
	buf = ft_strsplit(field, '\n');
	if (buf == NULL)
		throw_error("strsplit returned NULL. **DAFUQ?!**");
	pivot = NULL;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4 && buf[y][x])
		{
			validate_neighbours((const char **) buf, x, y);
			if (buf[y][x] == '#')
			{
				if (pivot == NULL)
					pivot = ft_create_el(x, y);
				append_el(new, x, y, pivot);
			}
		}
	}
	return (new);
}

void		read_figures(char *file)
{
	int			fd;
	char		letter;
	char		buffer[21];
	t_figure	*copy;
	long long	bytes;

	copy = NULL;
	g_figure_list = NULL;
	fd = open(file, O_RDONLY);
	letter = 'A';
	if (fd == -1)
		throw_error("File not found.");
	while ((bytes = read(fd, buffer, 21)) > 0)
		if ((bytes == 19 || bytes == 21) && letter++ < 'Z')
		{
			printf("%s", buffer);
			if (g_figure_list == NULL)
			{
				g_figure_list = create_figure(buffer);
				copy = g_figure_list;
			}
			else
			{
				g_figure_list->next = create_figure(buffer);
				g_figure_list = g_figure_list->next;
			}
			printf("%d\n", validate_figure(g_figure_list));
		}
		else
			throw_error("Invalid data format or too many pieces.");
	g_figure_list = copy;
	close(fd);
}
