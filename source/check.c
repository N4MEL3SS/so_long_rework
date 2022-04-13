# include "game.h"

void	check_extension(char *map_path)
{
	int	len;

	len = (int)ft_strlen(map_path);
	if (len < 5)
		terminate(ERR_LEN, NULL);
	if ((map_path[len - 4] != '.') && (map_path[len - 3] != 'b')
		&& (map_path[len - 2] != 'e') && (map_path[len - 1] != 'r'))
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

int	check_arg(int argc, char **map)
{
	if (argc < 2)
		terminate(ERR_ARG0, NULL);
	if (argc > 2)
		ft_putendl(WAR_ARGS);
	check_extension(map[1]);
	return (check_open(map[1]));
}
