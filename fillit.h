/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcherend <dcherend@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:54:55 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/13 19:11:53 by dcherend         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

# define ABS(a) (a < 0 ? -a : a)
# define SUCCESS 0				 /* pizdec useful */

typedef	struct		s_el
{
	int				x;
	int				y;
	struct s_el		*next;
}					t_el;

typedef	struct		s_figure
{
	char			letter;
	size_t			width;
	size_t			height;
	t_el			*scheme;
	struct s_figure	*next;
}					t_figure;

t_figure			*g_figure_list;
int					g_size;

t_el				*ft_create_el(int x, int y);
t_figure			*ft_create_figure(t_el *scheme);
char				**ft_fill_matrix(char **matrix, t_figure *fig);
t_figure			*ft_create_set(t_figure *fig);
void				ft_define_sizes(t_figure *fig);
void				ft_print_scheme(char **field);

/*
** I/O
*/
t_figure			*read_figures(char *file);
void				print_figure(t_figure *figure, int x, int y);
t_el				*append_el(t_figure *figure, int x, int y, t_el *pivot);
t_figure			*ft_create_figure_empty(void);
t_figure			*create_figure(const char *field);

/*
** Validation
*/
void				validate_neighbours(const char **fld, int x, int y);
t_figure			*validate_figure(const t_figure *figure);
void				throw_error(char *message);

/*
** Alternative solution
*/
char				**matrix_realloc(char **matrix, size_t size);
int					solve(t_figure *list, char **matrix);

#endif
