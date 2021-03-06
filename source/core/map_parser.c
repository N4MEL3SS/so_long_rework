/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:25:34 by celadia           #+#    #+#             */
/*   Updated: 2022/05/06 18:15:42 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	chcek_first_last_line(char *line)
{
	while (line && *line && *line != '\n' && *line != '\0')
	{
		if (*line++ != '1')
			terminate(ERR_MAP_W, NULL);
	}
}

void	check_extension(char *map_path)
{
	int	len;

	len = (int)ft_strlen(map_path);
	if (len < 5 || map_path[len - 5] == '/')
		terminate(ERR_LEN, NULL);
	if (!((map_path[len - 4] == '.') && (map_path[len - 3] == 'b')
			&& (map_path[len - 2] == 'e') && (map_path[len - 1] == 'r')))
		terminate(ERR_EXT, NULL);
}

int	check_open(char *map_path)
{
	int		fd;
	ssize_t	readfile;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		terminate(ERR_FILE, NULL);
	readfile = read(fd, "", 0);
	if (readfile < 0)
		terminate(ERR_READ, NULL);
	return (fd);
}

void	map_read(int fd, t_map *map)
{
	int		i;

	i = -1;
	map->arr = (char **)mem_alloc(sizeof(char *) * map->row);
	while (++i < map->row)
		map->arr[i] = get_next_line(fd, map->col);
	map->col--;
	close(fd);
}

void	map_parser(int argc, char **map_path, t_game *game)
{
	int	fd;

	if (argc < 2)
		terminate(ERR_ARG0, NULL);
	if (argc > 2)
		terminate(ERR_ARGS, NULL);
	check_extension(map_path[1]);
	fd = check_open(map_path[1]);
	check_map(fd, game);
	fd = open(map_path[1], O_RDONLY);
	map_read(fd, game->map);
	chcek_first_last_line(game->map->arr[0]);
	chcek_first_last_line(game->map->arr[game->map->row - 1]);
}
