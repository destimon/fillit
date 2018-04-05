/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 17:30:53 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/05 18:39:18 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

void	throw_error(char *message)
{
	write(1, "error\n", 6);
	if (message)
	{
		ft_putstr_fd(message, 1);
		ft_putchar_fd('\n', 1);
	}
	exit(1);
}

void		validate_point(const char **field, int i, int j)
{
	if ((field[i][j] != '.' && field[i][j] != '\n') || (field[i][3] != '\n'))
		throw_error("Invalid character in buffer.");
	if ()
}

t_figure	*create_figure(const char *field, const char letter)
{
	int 		i;
	int 		j;
	char 		**buf;
	t_figure	*new;

	new = construct_figure();
	if (field == NULL)
		throw_error("field == NULL.");
	buf = ft_strsplit(field, '\n');
	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 4)
		{
			validate_point((const char **)buf, i, j);
			if (buf[i][j] == '#')
			{

			}
			j++;
		}
		i++;
	}
	return (new);
}

void	read_tetriminos(char *file)
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

int		main(int argc, char **argv)
{
	read_tetriminos(argv[1]);
	return 0;
}


/*
void	ft_print_scheme(char **matrix)
{
	int	i;

	i = 1;
	while (matrix[i])
	{
		ft_putendl(matrix[i]);
		i++;
	}
}

int	main(void)
{
	char 		**matrix;
	int		i;
	t_el 		*one;
	t_el 		*two;
	t_el		*three;
	t_figure 	*alone;

	i = 0;
	one = ft_create_el(1, 1);
	two = ft_create_el(1, 2);
	three = ft_create_el(1, 5);
	one->next = two;
	two->next = three;
	alone = ft_create_figure(one);
	matrix = (char**)malloc(sizeof(*matrix) * 5);
	while (i < 4)
	{
		matrix[i] = ft_strdup("....");
		i++;
	}
	matrix[i] = NULL;
	ft_fill_matrix(matrix, alone);
	ft_print_scheme(matrix);
	return (0);	
}
 */
