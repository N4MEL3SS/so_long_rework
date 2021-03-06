/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:18:30 by celadia           #+#    #+#             */
/*   Updated: 2022/04/22 11:22:09 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# include "utils.h"
# include "error_msg.h"

# include "keycode_mac.h"

# define BUFF_SIZE 32
# define SCALE 32

# define FRAME 24
# define FRAME_X2 48

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			frame;
	int			ghost;
	int			width;
	int			height;
	t_map		*map;
	t_play		*player;
	t_play		*ghost1;
	t_play		*ghost2;
	t_spr		*sprite;
}				t_game;

void	check_map(int fd, t_game *game);
void	map_parser(int argc, char **map_path, t_game *game);

void	game_init(t_game *game, t_map *map, t_spr *spr, t_play *pl);
void	key_arr_init(t_play *play, int speed);

void	pre_render(t_game *game);
void	hook(t_game *game);
int		render_loop(t_game *game);

int		mc_up_down(char **map_arr, t_play *pl, int vector);
int		mc_left_right(char **map_arr, t_play *pl, int vector);

void	player_move(t_game *game, t_map *map, t_play *pl);
void	ghost_move(t_game *game, t_map *map, t_play *gh, int shift);
void	ft_move_msg(char *str, int n, t_game *game);
void	animation(t_game *game, t_img **img, t_play *pl);
void	door_anim(t_game *game);
int		close_win(t_game *game);
void	pos_init(t_game *game, int x, int y, int index);

void	finish(t_game *game, char *str, char *color);
int		key_control_press(int key, t_game *game);
void	ghost_check(t_game *game);

void	ft_exit(t_game *game);

#endif //GAME_H
