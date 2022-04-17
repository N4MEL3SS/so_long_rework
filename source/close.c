#include "game.h"

int	close_win(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}
