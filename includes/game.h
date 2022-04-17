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

# define B_SIZE 32
# define SCALE 32
# define SCALE_X2 64
# define KEY_ARR_SIZE 4

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		*map;
	t_pl		*player;
	t_spr		*sprite;
	int			width;
	int			height;
	int			pl_pos_x;
	int			pl_pos_y;
	int			key_array[KEY_ARR_SIZE];
}				t_game;

void	game_init(t_game *game, t_map *map, t_spr *spr);

void	ft_error(void);
size_t	ft_strlen(const char *str);
void	ft_message(const char *str);
void	ft_warning(const char *str);
void	terminate(const char *str, void *address);
void	*mem_alloc(size_t size);

int		close_win(t_game *game);
void	pre_render(t_game *game);
int		render_loop(t_game *game);
void	hook(t_game *game);
void	free_ptr(t_pl **ptr);
void	player_pos_init(t_mchk *op, int x);

int		key_control_press(int key, t_game *game);
int		key_control_release(int key, t_game *game);
void	player_move(int *array, t_game *game);

#endif //GAME_H
