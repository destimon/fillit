/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 19:18:51 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/05 19:48:37 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		validate_figure(const t_figure *figure)
{

}

void		validate_point(const char **field, int x, int y)
{
	if ((field[y][x] != '.' && field[y][x] != '\n') || (field[y][3] != '\n'))
		throw_error("Invalid character in buffer.");
	if (x < )
}

t_figure	*create_figure(const char *field, const char letter)
{
	int			y;
	int			x;
	char		**buf;
	t_el		*pivot;
	t_figure	*new;

	new = construct_figure();
	buf = ft_strsplit(field, '\n');
	if (buf == NULL)
		throw_error("strsplit returned NULL");
	pivot = NULL;
	y = -1;
	while (++y < 5)
	{
		x = 0;
		while (x < 4)
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

void		read_tetriminos(char *file)
{
	int			fd;
	char 		letter;
	char		buffer[21];
	long long	bytes;

	fd = open(file, O_RDONLY);
	letter = 'A';
	if (fd == -1)
		return ;
	while ((bytes = read(fd, buffer, 21)) > 0)
		if ((bytes == 20 || bytes == 21) && letter + 1 <= 'Z')
			create_figure(buffer, letter++);
		else
			throw_error("Invalid data format or too many pieces");
	close(fd);
}
