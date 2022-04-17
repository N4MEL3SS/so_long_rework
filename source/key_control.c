#include "game.h"

void	player_map_move_2point(int *array, t_game *game)
{
	int	x_up;
	int	y_up;
	int	x_down;
	int	y_down;

	x_up = game->pl_pos_x / SCALE;
	y_up = game->pl_pos_y / SCALE;
	x_down = (game->pl_pos_x + SCALE - 1) / SCALE;
	y_down = (game->pl_pos_y + SCALE - 1) / SCALE;
	if (game->map->map_arr[y_up][x_up] == '1' && \
		game->map->map_arr[y_up][x_down] == '1')
		game->pl_pos_y += array[3];
	if (game->map->map_arr[y_up][x_up] == '1' && \
		game->map->map_arr[y_down][x_up] == '1')
		game->pl_pos_x += array[0];
	if (game->map->map_arr[y_down][x_down] == '1' && \
		game->map->map_arr[y_up][x_down] == '1')
		game->pl_pos_x -= array[2];
	if (game->map->map_arr[y_down][x_down] == '1' && \
		game->map->map_arr[y_down][x_up] == '1')
		game->pl_pos_y -= array[1];
}

void	player_map_move_1point(int *array, t_game *game)
{
	int	x_up;
	int	y_up;
	int	x_down;
	int	y_down;

	x_up = game->pl_pos_x / SCALE;
	y_up = game->pl_pos_y / SCALE;
	x_down = (game->pl_pos_x + SCALE - 1) / SCALE;
	y_down = (game->pl_pos_y + SCALE - 1) / SCALE;
	if (game->map->map_arr[y_up][x_up] == '1' && array[3] > 0)
		game->pl_pos_y += array[3];
	else if (game->map->map_arr[y_up][x_down] == '1' && array[3] > 0)
		game->pl_pos_y += array[3];
	if (game->map->map_arr[y_up][x_down] == '1' && array[2] > 0)
		game->pl_pos_x -= array[2];
	else if (game->map->map_arr[y_down][x_down] == '1' && array[2] > 0)
		game->pl_pos_x -= array[2];
	if (game->map->map_arr[y_down][x_down] == '1' && array[1] > 0)
		game->pl_pos_y -= array[1];
	else if (game->map->map_arr[y_down][x_up] == '1' && array[1] > 0)
		game->pl_pos_y -= array[1];
	if (game->map->map_arr[y_up][x_up] == '1' && array[0] > 0)
		game->pl_pos_y += array[0];
	else if (game->map->map_arr[y_down][x_up] == '1' && array[0] > 0)
		game->pl_pos_x += array[0];
}

void	player_move(int *array, t_game *game)
{
	game->pl_pos_x += array[2];
	game->pl_pos_x -= array[0];
	game->pl_pos_y += array[1];
	game->pl_pos_y -= array[3];
	player_map_move_2point(array, game);
	player_map_move_1point(array, game);
}

int	key_control_press(int key, t_game *game)
{
	if (key == A_KEY || key == D_KEY || key == W_KEY || key == S_KEY)
		game->key_array[key % 10] = 4;
	else if (key == ESC)
		close_win(game);
	return (0);
}

int	key_control_release(int key, t_game *game)
{
	if (key == A_KEY || key == D_KEY || key == W_KEY || key == S_KEY)
		game->key_array[key % 10] = 0;
	return (0);
}
