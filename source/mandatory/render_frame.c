/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:26:49 by celadia           #+#    #+#             */
/*   Updated: 2022/04/22 09:10:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	render_loop(t_game *game)
{
	player_move(game, game->map, game->player);
	animation(game, game->sprite->pl_anim, game->player);
	door_anim(game);
	if (game->player->collect == 0)
		ft_exit(game);
	if (game->frame == FRAME_X2 / PL_SPEED)
		game->frame = -1;
	game->frame++;
	return (0);
}
