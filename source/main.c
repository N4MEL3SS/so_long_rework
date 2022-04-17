#include "game.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	t_spr	spr;
	t_game	game;

	map_parser(argc, argv, &map);
	game_init(&game, &map, &spr);
	pre_render(&game);
	hook(&game);
	return (0);
}
