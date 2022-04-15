#include "game.h"

int	main(int argc, char *argv[])
{
	t_mchk	opt;
	t_map	map;

	map_init(&map);
	check_map(check_arg(argc, argv), &opt, &map);
	map.map_path = ++argv;
	return (0);
}
