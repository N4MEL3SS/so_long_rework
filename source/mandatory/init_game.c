/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:25:14 by celadia           #+#    #+#             */
/*   Updated: 2022/04/22 10:16:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	pos_init(t_game *game, int x, int y, int index)
{
	if (index == PLAYER_INDEX)
	{
		game->player->win_pos_x = x * SCALE;
		game->player->win_pos_y = y * SCALE;
	}
	if (index == EXIT_INDEX_CL)
	{
		game->map->ex_pos_x = x;
		game->map->ex_pos_y = y;
	}
}

void	key_arr_init(t_play *play, int speed)
{
	play->key_array[CENTER] = 0;
	play->key_array[UP] = -speed;
	play->key_array[DOWN] = speed;
	play->key_array[LEFT] = -speed;
	play->key_array[RIGHT] = speed;
}

void	player_init(t_play *pl)
{
	pl->vector = 0;
	pl->n_vector = 0;
	pl->move_count = 0;
	key_arr_init(pl, PL_SPEED);
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
