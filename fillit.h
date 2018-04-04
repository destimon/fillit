#ifndef FILLIT_H
# define FILLIT_H

#include <stdlib.h>
#include "libft/libft.h"

typedef	struct		s_el
{
	int 		x;
	int		y;
	struct s_el	*next;
}			t_el;

typedef	struct		s_figure
{
	t_el		*scheme;
	struct s_figure	*next;
}			t_figure;

#endif
