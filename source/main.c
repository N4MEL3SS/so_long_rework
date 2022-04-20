#include "game.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	t_spr	spr;
	t_game	game;
	t_play	pl;

	map_parser(argc, argv, &map, &pl);
	game_init(&game, &map, &spr, &pl);
	pre_render(&game);
	hook(&game);
	return (0);
}
