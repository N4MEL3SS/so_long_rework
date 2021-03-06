/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control_linux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:17:16 by celadia           #+#    #+#             */
/*   Updated: 2022/04/22 11:17:16 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	key_control_press(int key, t_game *game)
{
	if (key == A_KEY)
		game->player->n_vector = 1;
	else if (key == S_KEY)
		game->player->n_vector = 2;
	else if (key == D_KEY)
		game->player->n_vector = 3;
	else if (key == W_KEY)
		game->player->n_vector = 4;
	else if (key == ESC)
		close_win(game);
	return (0);
}
