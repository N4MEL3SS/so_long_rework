/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ghost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:26:35 by celadia           #+#    #+#             */
/*   Updated: 2022/04/22 11:33:27 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	player_position_y(t_play *pl, t_play *gh)
{
	if (gh->win_pos_y == pl->win_pos_y)
		return (pl->vector);
	if (gh->win_pos_y > pl->win_pos_y)
		return (UP);
	else
		return (DOWN);
}

int	player_position_x(t_play *pl, t_play *gh, int shift)
{
	if (gh->win_pos_x == pl->win_pos_x)
		return ((pl->vector + shift) % 4);
	if (gh->win_pos_x > pl->win_pos_x)
		return (LEFT);
	else
		return (RIGHT);
}

void	ghost_move(t_game *game, t_map *map, t_play *gh, int shift)
{
	collect_redraw(game, map, gh);
	gh->n_vector = player_position_y(game->player, gh);
	gh->vector = player_position_x(game->player, gh, shift);
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
}

void	ghost_check(t_game *game)
{
	int		i1;
	int		i2;
	int		j1;
	int		j2;

	i1 = game->ghost1->win_pos_y / SCALE;
	j1 = game->ghost1->win_pos_x / SCALE;
	if ((game->player->win_pos_x + 16) / SCALE == j1 && \
		(game->player->win_pos_y + 16) / SCALE == i1)
		finish(game, DIE, RED);
	i2 = game->ghost2->win_pos_y / SCALE;
	j2 = game->ghost2->win_pos_x / SCALE;
	if ((game->player->win_pos_x + 16) / SCALE == j2 && \
		(game->player->win_pos_y + 16) / SCALE == i2)
		finish(game, DIE, RED);
}
