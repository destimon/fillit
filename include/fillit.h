/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasiu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 15:54:55 by vtarasiu          #+#    #+#             */
/*   Updated: 2018/04/21 14:01:40 by vtarasiu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define ABS(a) (a < 0 ? -(a) : a)

typedef struct		s_el
{
	int				x;
	int				y;
	struct s_el		*next;
}					t_el;

typedef struct		s_figure
{
	char			letter;
	t_el			*scheme;
	struct s_figure	*next;
}					t_figure;

typedef struct		s_field
{
	char			**field;
	int				size;
}					t_field;

t_figure			*g_figure_list;

t_el				*ft_create_el(int x, int y);

/*
** I/O
*/
t_figure			*read_figures(char *file);
void				print_matrix(t_field *matrix);
void				println_matrix(t_field *matrix);
void				print_char_matrix(char **matrix);
t_el				*append_el(t_figure *figure, int x, int y, t_el *pivot);
t_figure			*ft_create_figure_empty(void);
t_figure			*create_figure(const char *field);
t_figure			*assign_letters(t_figure *list);

/*
** Validation
*/
void				throw_error(char *message);
int					list_size(t_figure *list);
t_figure			*validate_list(t_figure *list);
t_figure			*validate_figure(t_figure *figure);
void				validate_neighbours(const char **fld, int x, int y);

/*
** Alternative solution
*/
t_field				*matrix_realloc(t_field *matrix, size_t size);
int					backtrace(t_field *matrix, t_figure *list);

/*
** Memory
*/
void				clear_figures(t_figure *list);
void				clear_field(t_field *field);

#endif
