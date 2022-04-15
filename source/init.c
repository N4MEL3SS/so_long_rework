#include "game.h"

void	map_opt_init(t_mchk	*opt)
{
	int		i;

	i = -1;
	while (++i < CHAR_ARR_SIZE)
		opt->char_arr[i] = 0;
}

void	map_err_init(t_merr *err)
{
	err->rowlen = 0;
	err->borders = 0;
	err->symbols = 0;
	err->way = 0;
	err->n_players = 0;
	err->n_ghosts = 0;
	err->n_collect = 0;
	err->n_exits = 0;
}

void	map_init(t_map *map)
{
	int		i;

	i = -1;
	while (++i < MAX_MAP)
	{
		map->col[i] = 0;
		map->row[i] = 0;
	}
}
