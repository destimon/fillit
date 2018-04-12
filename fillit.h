#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

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

t_el				*ft_create_el(int x, int y);
t_figure			*ft_create_figure(t_el *scheme);
char				**ft_fill_matrix(char **matrix, t_figure *fig);
char				**ft_solve_matrix(char **matrix, t_figure *fig);
t_figure			*ft_create_set(t_figure *fig);
void				ft_define_sizes(t_figure *fig);
void				ft_print_scheme(char **field);

void				read_figures(char *file);
void				print_figure(t_figure *figure, int x, int y);
t_el				*append_el(t_figure *figure, int x, int y, t_el *pivot);
t_figure			*ft_create_figure_empty(void);
t_figure			*create_figure(const char *field);
void				throw_error(char *message);

#endif
