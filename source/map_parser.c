#include "game.h"

void	map_read(int fd, t_map *map)
{
	int		i;

	i = -1;
	map->map = (char **)mem_alloc(sizeof(char *) * map->row[0]);
	while (++i < map->row[0])
	{
		map->map[i] = get_next_line(fd, map->col[0] + 1);
		map->map[i][map->col[0]] = '\0';
	}
}

/* Read just first map */
void	map_parser(t_map *map)
{
	int	fd;

	fd = open(map->map_path[0], O_RDONLY);
	map_read(fd, map);
}
