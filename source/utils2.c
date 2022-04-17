#include "game.h"

void	free_ptr(t_pl **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	terminate(const char *str, void *address)
{
	free(address);
	address = NULL;
	ft_error();
	ft_message(str);
	exit(EXIT_FAILURE);
}

void	*mem_alloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		terminate(ERR_MALLOC, ptr);
	return (ptr);
}
