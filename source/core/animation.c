/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:25:58 by celadia           #+#    #+#             */
/*   Updated: 2022/04/22 10:18:35 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	animation(t_game *game, t_img **img, t_play *pl)
{
	if (pl->vector && game->frame <= FRAME / PL_SPEED)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			img[pl->vector]->img_ptr, pl->win_pos_x, pl->win_pos_y);
	else if (pl->vector && game->frame <= FRAME_X2 / PL_SPEED)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			img[pl->vector + SHIFT]->img_ptr, pl->win_pos_x, pl->win_pos_y);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			img[0]->img_ptr, pl->win_pos_x, pl->win_pos_y);
}

void	door_anim(t_game *game)
{
	if (game->player->collect == 0)
	{
		game->map->arr[game->map->ex_pos_y][game->map->ex_pos_x] = '0';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->stat_img[EXIT_INDEX_OP]->img_ptr,
			game->map->ex_pos_x * SCALE, game->map->ex_pos_y * SCALE);
	}
}
