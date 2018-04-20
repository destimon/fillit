/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_figures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:18:51 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/16 15:18:16 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Possible bug in here.
*/

t_figure	*validate_list(t_figure *list)
{
	if (list_size(list) > 26)
		throw_error();
	return (list);
}

static char	**get_buf(const char *field)
{
	char		**buf;

	buf = ft_strsplit(field, '\n');
	if (buf == NULL)
		throw_error();
	return (buf);
}

static int	get_fd(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		throw_error();
	return (fd);
}

t_figure	*create_figure(const char *field)
{
	int			y;
	int			x;
	char		**buf;
	t_el		*pivot;
	t_figure	*new;

	new = ft_create_figure_empty();
	buf = get_buf(field);
	pivot = NULL;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4 && buf[y][x])
		{
			validate_neighbours((const char **)buf, x, y);
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

t_figure	*read_figures(char *file)
{
	int			fd;
	char		buffer[21];
	t_figure	*list_head;
	long long	bytes;

	list_head = NULL;
	g_figure_list = NULL;
	fd = get_fd(file);
	while ((bytes = read(fd, buffer, 21)) > 0)
		if ((bytes == 19 || bytes == 21))
			if (g_figure_list == NULL)
			{
				g_figure_list = validate_figure(create_figure(buffer));
				list_head = g_figure_list;
			}
			else
			{
				g_figure_list->next = validate_figure(create_figure(buffer));
				g_figure_list = g_figure_list->next;
			}
		else
			throw_error();
	g_figure_list = validate_list(list_head);
	close(fd);
	return (g_figure_list);
}
