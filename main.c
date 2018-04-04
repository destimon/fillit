#include "fillit.h"

t_el	*ft_create_el(int x, int y)
{
	t_el 	*new;

	if (x && y)
	{
		new = (t_el*)malloc(sizeof(t_el));
		if (new)
		{
			new->x = x;
			new->y = y;
			new->next = NULL;
			return (new);
		}
	}
	return (NULL);
}

t_figure	*ft_create_figure(t_el *scheme)
{
	t_figure	*new;

	if (scheme)
	{
		new = (t_figure*)malloc(sizeof(t_figure));
		if (new)
		{
			new->scheme = scheme;
			new->next = NULL;
		}
		return (new);
	}
	return (NULL);
}

void	ft_print_scheme(char **matrix)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		ft_putendl(matrix[i]);
		i++;
	}
}

void	ft_fill_matrix(char **matrix, t_figure *fig)
{
	int	i;
	int	j;
	int	len;
	t_el	*tmp;

	len = 4;
	tmp = fig->scheme;
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			j = 0;
			while (j < len)
			{
				if ((i == tmp->x) && (j == tmp->y))
					matrix[i][j] = 'A';
				j++;
			}
			i++;
		}
		tmp = tmp->next;
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
	three = ft_create_el(1, 7);
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
