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
	write(1, "Error!", 5);
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

void	ft_move_msg(char *str, int n, t_game *game)
{
	char	msg[4];
	int		i;

	i = -1;
	msg[++i] = (char)(n / 100 + 48);
	msg[++i] = (char)(n % 100 / 10 + 48);
	msg[++i] = (char)(n % 10 + 48);
	msg[++i] = '\0';
	write(1, BLUE, COLOR_SIZE);
	write(1, str, ft_strlen(str));
	write(1, msg, ft_strlen(msg));
	write(1, COLOR_END, COLOR_SIZE);
	write(1, "\n", 1);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->sprite->stat_img[EMPTY_INDEX]->img_ptr, 0, 0);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 1, 4, 0x00FFFFFF, msg);
}
