#include "game.h"

void	hook(t_game *game)
{
	mlx_hook(game->win_ptr, DESTROY, 0, close_win, game);
	mlx_hook(game->win_ptr, KEY_PRESS, 1L << 0,
		key_control_press, game);
	mlx_loop_hook(game->mlx_ptr, render_loop, game);
	mlx_loop(game->mlx_ptr);
}
