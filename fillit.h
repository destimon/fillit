#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include "libft/libft.h"

typedef	struct		s_el
{
	int 			x;
	int				y;
	struct 	s_el	*next;
}					t_el;

typedef	struct		s_figure
{
	t_el			*scheme;
	struct s_figure	*next;
}					t_figure;

t_el				*ft_create_el(int x, int y);
t_figure			*ft_create_figure(t_el *scheme);
void				ft_fill_matrix(char **matrix, t_figure *fig);

t_figure			*construct_figure();
t_figure			*create_figure(const char *field, const char letter);
void				throw_error(char *message);

#endif
