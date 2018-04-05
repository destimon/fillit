#include "fillit.h"

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