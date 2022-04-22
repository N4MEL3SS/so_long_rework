/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:27:01 by celadia           #+#    #+#             */
/*   Updated: 2022/04/20 12:43:50 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	ft_finish(t_game *game, char *str, char *color)
{
	ft_message(str, color);
	close_win(game);
}

void	ft_exit(t_game *game)
{
	if (game->player->win_pos_x == game->map->ex_pos_x * SCALE && \
		game->player->win_pos_y == game->map->ex_pos_y * SCALE)
		ft_finish(game, CONG, GREEN);
}

void	terminate(const char *str, void *address)
{
	free(address);
	address = NULL;
	ft_error();
	ft_message(str, GREEN);
	exit(EXIT_FAILURE);
}

void	*mem_alloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		terminate(ERR_MALLOC, ptr);
	return (ptr);
}
