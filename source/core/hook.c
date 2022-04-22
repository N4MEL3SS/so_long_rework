/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:26:15 by celadia           #+#    #+#             */
/*   Updated: 2022/04/20 12:26:15 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	hook(t_game *game)
{
	mlx_hook(game->win_ptr, DESTROY, 0, close_win, game);
	mlx_hook(game->win_ptr, KEY_PRESS, 1L << 0,
		key_control_press, game);
	mlx_loop_hook(game->mlx_ptr, render_loop, game);
	mlx_loop(game->mlx_ptr);
}
