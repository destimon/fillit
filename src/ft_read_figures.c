/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_figures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:18:51 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/21 18:23:25 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fillit.h"

t_figure	*val_list(t_figure *list)
{
	if (list_size(list) > 26)
		throw_error("Too many figures.");
	return (list);
}

static char	**get_buf(const char *field)
{
	char		**buf;

	buf = ft_strsplit(field, '\n');
	if (buf == NULL)
		throw_error("Strsplit returned null");
	return (buf);
}

static int	get_fd(char *file)
{
	int			fd;
	int			i;
	long long	bytes;
	char		buf[1024];

	i = -1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		throw_error("File does not exist");
	if ((bytes = read(fd, buf, 1024)) % 21 != 20)
		throw_error("File size does not match.");
	while (++i < bytes)
		if (buf[i] != '\n' && buf[i] != '#' && buf[i] != '.')
			throw_error("Invalid character.");
	close(fd);
	return (open(file, O_RDONLY));
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
	char		buf[21];
	t_figure	*list_head;
	long long	bytes;

	list_head = NULL;
	g_figure_list = NULL;
	fd = get_fd(file);
	while ((bytes = read(fd, buf, 21)) > 0)
		if ((bytes == 20 || bytes == 21) && buf[4] == '\n')
			if (g_figure_list == NULL)
			{
				g_figure_list = val_fig(create_figure(vb(buf, bytes)));
				list_head = g_figure_list;
			}
			else
			{
				g_figure_list->next = val_fig(create_figure(vb(buf, bytes)));
				g_figure_list = g_figure_list->next;
			}
		else
			throw_error("Invalid data format.");
	g_figure_list = val_list(list_head);
	close(fd);
	return (g_figure_list);
}
