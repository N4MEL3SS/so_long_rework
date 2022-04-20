#ifndef GAME_H
# define GAME_H

# include <stdlib.h> /* malloc, free, exit */
# include <stdio.h> /* perror, strerror */
# include <fcntl.h> /* open */
# include <unistd.h> /* read, write, close */

# include "mlx.h"
# include "map.h"
# include "player.h"
# include "sprite.h"
# include "get_next_line.h"
# include "keycode_mac.h"
# include "utils.h"
# include "error_msg.h"

# define BUFF_SIZE 32
# define SCALE 32

# define FRAME 24
# define FRAME_X2 (FRAME * 2)

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			frame;
	int			width;
	int			height;
	t_map		*map;
	t_play		*player;
	t_spr		*sprite;
}				t_game;

void	check_map(int fd, t_map *map, t_play *pl);
void	map_parser(int argc, char **map_path, t_map *map, t_play *pl);

void	game_init(t_game *game, t_map *map, t_spr *spr, t_play *pl);

void	pre_render(t_game *game);
void	hook(t_game *game);
int		render_loop(t_game *game);

void	player_move(t_game *game, t_map *map, t_play *pl);
void	ft_move_msg(char *str, int n, t_game *game);
void	animation(t_game *game, t_img **img, t_play *pl);
int		close_win(t_game *game);
void	pos_init(t_mchk *op, int x, int index);

int		key_control_press(int key, t_game *game);

#endif //GAME_H
