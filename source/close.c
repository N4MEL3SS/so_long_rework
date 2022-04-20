#include "game.h"

void	free_pl_sprite(t_img *img)
{
	int		i;

	i = -1;
	while (++i < 9)
		free(img[i].img_ptr);
}

void	free_stat_sprite(t_img *img)
{
	int		i;

	i = -1;
	while (++i < CHAR_ARR_SIZE + 1)
		free(img[i].img_ptr);
}

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
//	free_pl_sprite(game->sprite->pl_anim[0]);
//	free_stat_sprite(game->sprite->stat_img[0]);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	exit(EXIT_SUCCESS);
}
