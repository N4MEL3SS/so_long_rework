#include "game.h"

int	key_control_press(int key, t_game *game)
{
	if (key == A_KEY || key == D_KEY || key == W_KEY || key == S_KEY)
		game->player->n_vector = key % 10 + 1;
	else if (key == ESC)
		close_win(game);
	return (0);
}
