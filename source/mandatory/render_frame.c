/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:26:49 by celadia           #+#    #+#             */
/*   Updated: 2022/04/20 12:27:22 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	pre_render(t_game *game)
{
	char	**arr;
	t_img	**stat;
	int		index;
	int		i;
	int		j;

	i = -1;
	arr = game->map->arr;
	stat = &game->sprite->stat_img[0];
	arr[game->player->win_pos_y / SCALE][game->player->win_pos_x / SCALE] = '0';
	while (++i < game->map->row)
	{
		j = -1;
		while (++j < game->map->col)
		{
			index = (int)((arr[i][j] - 47 + (arr[i][j] / 69)) % 10);
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				stat[index]->img_ptr, j * SCALE, i * SCALE);
		}
	}
	arr[game->map->ex_pos_y][game->map->ex_pos_x] = '1';
}



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
