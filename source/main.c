#include "game.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	t_spr	spr;
	t_game	game;
	t_play	pl;

	game.map = &map;
	game.player = &pl;
	game.ghost1 = (t_play *)mem_alloc(sizeof(t_play));
	game.ghost2 = (t_play *)mem_alloc(sizeof(t_play));
	map_parser(argc, argv, &game);
	game_init(&game, &map, &spr, &pl);
	pre_render(&game);
	hook(&game);
	return (0);
}
