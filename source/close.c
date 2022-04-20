#include "game.h"

void	free_map(t_map *map)
{
	while (--map->row > -1)
		free(map->arr[map->row]);
}

int	close_win(t_game *game)
{
	free(game->ghost1);
	free(game->ghost2);
	free_map(game->map);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}
