/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:26:49 by celadia           #+#    #+#             */
/*   Updated: 2022/04/22 11:29:38 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	finish(t_game *game, char *str, char *color)
{
	ft_message(str, color);
	close_win(game);
}

int	render_loop(t_game *game)
{
	player_move(game, game->map, game->player);
	ghost_move(game, game->map, game->ghost1, 2);
	ghost_move(game, game->map, game->ghost2, 4);
	ghost_check(game);
	animation(game, game->sprite->pl_anim, game->player);
	animation(game, game->sprite->gh1_anim, game->ghost1);
	animation(game, game->sprite->gh2_anim, game->ghost2);
	door_anim(game);
	if (game->player->win_pos_x == game->map->ex_pos_x * SCALE && \
		game->player->win_pos_y == game->map->ex_pos_y * SCALE)
		finish(game, CONG, GREEN);
	if (game->frame == FRAME_X2 / PL_SPEED)
		game->frame = -1;
	game->frame++;
	return (0);
}
