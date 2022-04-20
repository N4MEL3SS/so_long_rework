#include "game.h"

void	pos_init(t_mchk *op, int x, int index)
{
	if (index == PLAYER_INDEX)
	{
		op->pl_pos_x = x;
		op->pl_pos_y = op->row - 1;
	}
	if (index == EXIT_INDEX_CL)
	{
		op->ex_pos_x = x;
		op->ex_pos_y = op->row - 1;
	}
}

void	player_init(t_play *pl)
{
	pl->score = 0;
	pl->vector = 0;
	pl->n_vector = 0;
	pl->move_count = 0;
	pl->key_array[CENTER] = 0;
	pl->key_array[UP] = -SPEED;
	pl->key_array[DOWN] = SPEED;
	pl->key_array[LEFT] = -SPEED;
	pl->key_array[RIGHT] = SPEED;
}

void	game_init(t_game *game, t_map *map, t_spr *spr, t_play *pl)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		terminate(ERR_MALLOC, game->mlx_ptr);
	game->width = map->col * SCALE;
	game->height = map->row * SCALE;
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->width, game->height, "not Pac-Man");
	game->frame = 0;
	game->map = map;
	game->player = pl;
	game->sprite = spr;
	player_init(pl);
	sprite_init(spr, game->mlx_ptr);
}
