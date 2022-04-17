#include "game.h"

t_img	*img_init(void *mlx_ptr, char *path)
{
	t_img	*img;

	img = (t_img *)mem_alloc(sizeof(t_img));
	img->width = 0;
	img->height = 0;
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, path,
			&img->width, &img->height);
	return (img);
}

void	sprite_init(t_spr *spr, void *mlx_ptr)
{
	spr->stat_img[COL_INDEX] = img_init(mlx_ptr, COL_IMG);
	spr->stat_img[EMPTY_INDEX] = img_init(mlx_ptr, EMPTY_IMG);
	spr->stat_img[WALL_INDEX] = img_init(mlx_ptr, WALL_IMG);
	spr->stat_img[EXIT_INDEX] = img_init(mlx_ptr, EXIT_IMG);
	spr->stat_img[PLAYER_INDEX] = img_init(mlx_ptr, PLAYER_IMG);
	spr->player_img = spr->stat_img[PLAYER_INDEX];
	spr->player2_img = img_init(mlx_ptr, PLAYER2_IMG);
}

void	player_pos_init(t_mchk *op, int x)
{
	op->pl_pos_x = x;
	op->pl_pos_y = op->row;
}

t_pl	*player_init(void)
{
	t_pl	*player;

	player = (t_pl *)mem_alloc(sizeof(t_pl));
	player->pos_x = SCALE;
	player->pos_y = SCALE;
	return (player);
}

void	game_init(t_game *game, t_map *map, t_spr *spr)
{
	game->map = map;
	game->sprite = spr;
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		terminate(ERR_MALLOC, game->mlx_ptr);
	game->width = map->width * SCALE;
	game->height = map->height * SCALE;
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->width, game->height, "not Pac-Man");
	sprite_init(game->sprite, game->mlx_ptr);
	game->pl_pos_x = map->pl_pos_x * SCALE;
	game->pl_pos_y = map->pl_pos_y * SCALE - 32;
	game->key_array[0] = 0;
	game->key_array[1] = 0;
	game->key_array[2] = 0;
	game->key_array[3] = 0;
}
