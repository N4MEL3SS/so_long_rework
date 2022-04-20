#include "game.h"

void	pre_render(t_game *game)
{
	char	**arr;
	t_img	**stat;
	int		index;
	int		i;
	int		j;

	i = -1;
	arr = game->map->arr;
	stat = &game->sprite->stat_img[0];
	arr[game->map->pl_pos_y][game->map->pl_pos_x] = '0';
	while (++i < game->map->row)
	{
		j = -1;
		while (++j < game->map->col)
		{
			index = (int)((arr[i][j] - 47 + (arr[i][j] / 69)) % 10);
			mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
				stat[index]->img_ptr, j * SCALE, i * SCALE);
		}
	}
	arr[game->map->ex_pos_y][game->map->ex_pos_x] = '1';
}

int	render_loop(t_game *game)
{

	player_move(game, game->map, game->player);
	animation(game, game->sprite->pl_anim, game->player);
	if (game->player->collect == 0)
	{
		game->map->arr[game->map->ex_pos_y][game->map->ex_pos_x] = '0';
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sprite->stat_img[EXIT_INDEX_OP]->img_ptr,
			game->map->ex_pos_x * SCALE, game->map->ex_pos_y * SCALE);
	}
	if (game->player->pos_x == game->map->ex_pos_x * SCALE && \
		game->player->pos_y == game->map->ex_pos_y * SCALE)
		close_win(game);
	if (game->frame == FRAME_X2 / SPEED)
		game->frame = -1;
	game->frame++;
	return (0);
}
