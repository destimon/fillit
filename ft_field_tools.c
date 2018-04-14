#include "fillit.h"

void		ft_del_field(t_field *fl)
{
	int	i;

	i = 0;
	if (fl)
	{
		while (i < fl->size)
		{
			ft_memdel((void**)&fl->field[i]);
			i++;
		}
		ft_memdel((void**)fl->field);	
		ft_memdel((void**)fl);
	}
}

t_field 	*ft_alloc_field(int	size)
{
	t_field		*fl;
	int			i;

	i = 0;
	fl = (t_field*)malloc(sizeof(t_field));
	if (fl)
	{
		fl->size = size;
		fl->field = (char**)ft_memalloc(sizeof(char*) * (size + 1));
		while (i < size)
		{
			fl->field[i] = ft_strnew(size);
			ft_memset(fl->field[i], '.', size);
			i++;
		}
	}
	return (fl);
}

t_field		*ft_realloc_field(t_field *fl, int size)
{
	t_field 	*new_fl;
	int			i;

	i = 0;
	new_fl = ft_alloc_field(size);
	while (i < fl->size)
	{
		ft_strncpy(new_fl->field[i], fl->field[i], fl->size);
		i++;
	}
	ft_del_field(fl);
	return (new_fl);
}

void	ft_print_field(t_field *fl)
{
	int	i;

	i = 0;
	while (fl->field[i])
	{
		ft_putendl(fl->field[i]);
		i++;
	}
}

int		ft_scanplace_field(t_field *fl, t_figure *fig, int i, int j)
{
	t_el 	*el;
	
	if (fl && fig)
	{
		el = fig->scheme;
		while (el)
		{
			if ((i + el->y) > fl->size || (j + el->x) > fl->size)
				return (0);
			if (fl->field[i + el->y][j + el->x] != '.')
				return (0);
			el = el->next;
		}
		return (1);
	}
	return (0);
}

void	ft_place_field(t_field *fl, t_figure *fig, int i, int j)
{
	t_el 	*el;

	if (fl && fig)
	{
		el = fig->scheme;
		while (el)
		{
			while ()
			fl->field[i + el->y][j + el->x] = fig->letter;
			el = el->next;
		}
	}
}