/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:18:51 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/07 16:56:37 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <printf.h>
#include "fillit.h"

void		validate_figure(const t_figure *figure)
{
	return ;
}

void		validate_point(const char **fld, int x, int y)
{
	if ((fld[y][x] != '.' && fld[y][x] != '\n' && fld[y][x] != '#'))
		throw_error("Invalid character in buffer.");
	if (fld[y][x] == '.')
		return ;
	if (x < 3 && y < 3 && x > 0 && y > 0)
	{
		if (fld[y + 1][x] == '#' || fld[y - 1][x] == '#' ||
			fld[y][x + 1] == '#' || fld[y][x - 1] == '#')
			return ;
	}
	/*else if (x > 0 && y > 0 && (fld[y - 1][x] == '#' || fld[y][x - 1] == '#'))
		return ;
	else if (x == 0 && y == 0 && (fld[y + 1][x] == '#' || fld[y][x + 1] == '#'))
		return ;
	else if (x == 0 && y > 0 && (fld[y - 1][x] == '#' || fld[y + 1][x] == '#' ||
			fld[y][x + 1] == '#'))
		return ;
	else if (x > 0 && y == 0 && (fld[y][x - 1] == '#' || fld[y][x + 1] == '#' ||
			fld[y + 1][x] == '#'))
		return ;
	else
		throw_error("Some point has no neighbours.");*/
}

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
		throw_error("strsplit returned NULL");
	pivot = NULL;
	y = -1;
	while (++y < 4)
	{
		x = 0;
		while (x < 4 && buf[y][x])
		{
			validate_point((const char **)buf, x, y);
			if (buf[y][x] == '#')
			{
				if (pivot == NULL)
					pivot = ft_create_el(x, y);
				append_el(new, x, y, pivot);
			}
			x++;
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
		throw_error("file not found");
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
		}
		else
			throw_error("Invalid data format or too many pieces");
	g_figure_list = copy;
	close(fd);
}
