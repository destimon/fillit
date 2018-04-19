#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_mem;

	if (!size && (char*)ptr)
		free(ptr);
	else if (!(char*)ptr)
	{
		ptr = (void*)malloc(sizeof(ptr) * size);
		return (ptr);
	}
	else
	{
		new_mem = (void*)malloc(sizeof(new_mem) * size);
		if (new_mem && (char*)ptr)
		{
			ft_memcpy(new_mem, ptr, ft_strlen(ptr));
			free(ptr);
			ptr = new_mem;
		}
		return (ptr);
	}
	return (NULL);
}
