#include "game.h"

# define FRAME 10

void	pre_render(t_game *game)
{
	char	**map_arr;
	t_img	**stat;
	int		index;
	int		i;
	int		j;

	i = -1;
	map_arr = game->map->map_arr;
	stat = &game->sprite->stat_img[0];
	map_arr[game->map->pl_pos_y][game->map->pl_pos_x] = '0';
	while (++i < game->map->height)
	{
		j = -1;
		while (++j < game->map->width)
		{
			index = (int)((map_arr[i][j] - 47 + (map_arr[i][j] / 69)) % 10);
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				stat[index]->img_ptr, j * SCALE, i * SCALE);
		}
	}
}

int	render_loop(t_game *game)
{
	static int	frame = 0;

	if (frame / FRAME == 0)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->stat_img[1]->img_ptr,
			game->pl_pos_x, game->pl_pos_y);
		player_move(game->key_array, game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->stat_img[2]->img_ptr,
			game->pl_pos_x, game->pl_pos_y);
	}
	else if (frame / FRAME == 1)
	{
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->stat_img[1]->img_ptr,
			game->pl_pos_x, game->pl_pos_y);
		player_move(game->key_array, game);
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->stat_img[2]->img_ptr,
			game->pl_pos_x, game->pl_pos_y);
	}
	if (frame == 2 * FRAME)
		frame = -1;
	frame++;
	return (0);
}
