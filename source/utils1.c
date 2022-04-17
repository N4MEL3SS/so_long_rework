#include "game.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*str && ++len)
		str++;
	return (len);
}

void	ft_error(void)
{
	write(1, RED, COLOR_SIZE);
	write(1, "Error", 5);
	write(1, COLOR_END, COLOR_SIZE);
	write(1, "\n", 1);
}

void	ft_message(const char *str)
{
	write(1, GREEN, COLOR_SIZE);
	write(1, str, ft_strlen(str));
	write(1, COLOR_END, COLOR_SIZE);
	write(1, "\n", 1);
}

void	ft_warning(const char *str)
{
	write(1, YELLOW, COLOR_SIZE);
	write(1, str, ft_strlen(str));
	write(1, COLOR_END, COLOR_SIZE);
	write(1, "\n", 1);
}

