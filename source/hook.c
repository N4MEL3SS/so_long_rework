#include "game.h"

int	key_control_press(int key, t_game *game)
{
	if (key == A_KEY || key == D_KEY || key == W_KEY || key == S_KEY)
		game->player->n_vector = key % 10 + 1;
	else if (key == ESC)
		close_win(game);
	return (0);
}

void	hook(t_game *game)
{
	mlx_hook(game->win_ptr, DESTROY, 0, close_win, game);
	mlx_hook(game->win_ptr, KEY_PRESS, 1L << 0,
		key_control_press, game);
	mlx_loop_hook(game->mlx_ptr, render_loop, game);
	mlx_loop(game->mlx_ptr);
}
