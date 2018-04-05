#include "fillit.h"

t_el	*ft_create_el(int x, int y)
{
	t_el 	*new;

	new = (t_el*)malloc(sizeof(t_el));
	if (new)
	{
		new->x = x;
		new->y = y;
		new->next = NULL;
		return (new);
	}
	return (NULL);
}
