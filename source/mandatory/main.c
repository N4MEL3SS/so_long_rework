/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:25:23 by celadia           #+#    #+#             */
/*   Updated: 2022/04/22 09:10:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	t_spr	spr;
	t_game	game;
	t_play	pl;

	game.map = &map;
	game.player = &pl;
	map_parser(argc, argv, &game);
	game_init(&game, &map, &spr, &pl);
	pre_render(&game);
	hook(&game);
	return (0);
}
