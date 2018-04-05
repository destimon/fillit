#include "fillit.h"

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
