#include "game.h"

void	animation(t_game *game, t_img **img, t_play *pl)
{
	if (pl->vector && game->frame <= FRAME / SPEED)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			img[pl->vector]->img_ptr, pl->pos_x, pl->pos_y);
	else if (pl->vector && game->frame <= FRAME_X2 / SPEED)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			img[pl->vector + SHIFT]->img_ptr, pl->pos_x, pl->pos_y);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			img[0]->img_ptr, pl->pos_x, pl->pos_y);
}
