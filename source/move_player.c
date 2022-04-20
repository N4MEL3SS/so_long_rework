#include "game.h"

int	mc_up_down(char **map_arr, t_play *pl, int vector)
{
	int		i;
	int		j;
	int		j2;

	j = pl->win_pos_x / SCALE;
	j2 = (pl->win_pos_x + 31) / SCALE;
	if (vector == UP)
	{
		i = (pl->win_pos_y + pl->key_array[vector]) / SCALE;
		if (map_arr[i][j] != '1' && map_arr[i][j2] != '1')
			return (1);
	}
	if (vector == DOWN)
	{
		i = (pl->win_pos_y + 31 + pl->key_array[vector]) / SCALE;
		if (map_arr[i][j] != '1' && map_arr[i][j2] != '1')
			return (1);
	}
	return (0);
}

int	mc_left_right(char **map_arr, t_play *pl, int vector)
{
	int		i;
	int		i2;
	int		j;

	i = pl->win_pos_y / SCALE;
	i2 = (pl->win_pos_y + 31) / SCALE;
	if (vector == LEFT)
	{
		j = (pl->win_pos_x + pl->key_array[vector]) / SCALE;
		if (map_arr[i][j] != '1' && map_arr[i2][j] != '1')
			return (1);
	}
	if (vector == RIGHT)
	{
		j = (pl->win_pos_x + 31 + pl->key_array[vector]) / SCALE;
		if (map_arr[i][j] != '1' && map_arr[i2][j] != '1')
			return (1);
	}
	return (0);
}

void	collect_check(char **map_arr, t_play *pl)
{
	int		x;
	int		y;

	x = pl->win_pos_x / SCALE;
	y = pl->win_pos_y / SCALE;
	if (map_arr[y][x] == 'C')
	{
		map_arr[y][x] = '0';
		pl->collect--;
	}
}

void	player_move(t_game *game, t_map *map, t_play *pl)
{
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->sprite->stat_img[EMPTY_INDEX]->img_ptr, pl->win_pos_x, pl->win_pos_y);
	if (pl->n_vector != pl->vector && (mc_up_down(map->arr, pl, pl->n_vector)
			|| mc_left_right(map->arr, pl, pl->n_vector)))
	{
		pl->vector = pl->n_vector;
		if (pl->vector == UP || pl->vector == DOWN)
			pl->win_pos_y += pl->key_array[pl->vector];
		if (pl->vector == LEFT || pl->vector == RIGHT)
			pl->win_pos_x += pl->key_array[pl->vector];
		ft_move_msg(MAP_MOVE, ++pl->move_count, game);
	}
	else if (pl->vector && (mc_up_down(map->arr, pl, pl->vector) || \
	mc_left_right(map->arr, pl, pl->vector)))
	{
		if (pl->vector == UP || pl->vector == DOWN)
			pl->win_pos_y += pl->key_array[pl->vector];
		if (pl->vector == LEFT || pl->vector == RIGHT)
			pl->win_pos_x += pl->key_array[pl->vector];
	}
	collect_check(map->arr, pl);
}
