#include "game.h"

void	pre_render(t_game *game)
{
	int		index;
	int		i;
	int		j;

	i = -1;
	game->map->arr[game->player->win_pos_y / SCALE] \
		[game->player->win_pos_x / SCALE] = '0';
	while (++i < game->map->row)
	{
		j = -1;
		while (++j < game->map->col)
		{
			index = (int)((game->map->arr[i][j] - 47 + \
					(game->map->arr[i][j] / 69)) % 10);
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				game->sprite->stat_img[index]->img_ptr,
				j * SCALE, i * SCALE);
		}
	}
	game->map->arr[game->map->ex_pos_y][game->map->ex_pos_x] = '1';
}
