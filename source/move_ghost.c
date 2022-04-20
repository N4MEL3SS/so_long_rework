#include "game.h"

void	collect_redraw(t_game *game, t_map *map, t_play *gh)
{
	int		i;
	int		j;

	i = gh->win_pos_y / SCALE;
	j = gh->win_pos_x / SCALE;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->sprite->stat_img[EMPTY_INDEX]->img_ptr,
		gh->win_pos_x, gh->win_pos_y);
	if (map->arr[i][j] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->stat_img[COL_INDEX]->img_ptr, j * SCALE, i * SCALE);
	if (map->arr[i + 1][j] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->stat_img[COL_INDEX]->img_ptr,
			j * SCALE, (i + 1) * SCALE);
	if (map->arr[i][j + 1] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->stat_img[COL_INDEX]->img_ptr,
			(j + 1) * SCALE, i * SCALE);
	if (map->arr[i + 1][j + 1] == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->stat_img[COL_INDEX]->img_ptr,
			(j + 1) * SCALE, (i + 1) * SCALE);
}

void	ghost_move(t_game *game, t_map *map, t_play *gh, int shift)
{
	collect_redraw(game, map, gh);
	gh->n_vector = (game->player->vector + shift) % 4;
	gh->vector = (game->player->vector + shift - 1) % 4;
	if (mc_up_down(map->arr, gh, gh->n_vector) || \
		mc_left_right(map->arr, gh, gh->n_vector))
	{
		if (gh->n_vector == UP || gh->n_vector == DOWN)
			gh->win_pos_y += gh->key_array[gh->n_vector];
		if (gh->n_vector == LEFT || gh->n_vector == RIGHT)
			gh->win_pos_x += gh->key_array[gh->n_vector];
	}
	if (mc_up_down(map->arr, gh, gh->vector) || \
		mc_left_right(map->arr, gh, gh->vector))
	{
		if (gh->vector == UP || gh->vector == DOWN)
			gh->win_pos_y += gh->key_array[gh->vector];
		if (gh->vector == LEFT || gh->vector == RIGHT)
			gh->win_pos_x += gh->key_array[gh->vector];
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->sprite->stat_img[GHOST_INDEX]->img_ptr, gh->win_pos_x, gh->win_pos_y);
}
