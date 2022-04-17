#ifndef MAP_H
# define MAP_H

# define CHAR_ARR_SIZE 5

# define COL_INDEX 0
# define EMPTY_INDEX 1
# define WALL_INDEX 2
# define EXIT_INDEX 3
# define PLAYER_INDEX 4

/* index = (char - 47 + (char / 69) % 10 */
/* opt_arr[0] = Collect (C)				 */
/* opt_arr[1] = Empty (1) 				 */
/* opt_arr[2] = Wall (0) 				 */
/* opt_arr[3] = Exit (E) 				 */
/* opt_arr[4] = Player (P) 				 */

typedef struct s_map_player
{
	int		pos_x;
	int		pos_y;
}				t_pl_pos;
/* pl_pos - player position*/

typedef struct s_map_enemy
{
	int		type;
	int		pos_x;
	int		pos_y;
}				t_en_pos;
/* en_pos - enemy position*/

typedef struct s_map_check
{
	int		row;
	int		col;
	int		char_arr[CHAR_ARR_SIZE];
	int		fl_line;
	int		pl_pos_x;
	int		pl_pos_y;
}				t_mchk;
/* first or last line flag */
/* mopt - map_check_option */

typedef struct s_map_err
{
	int	rowlen;
	int	borders;
	int	n_players;
	int	n_ghosts;
	int	n_collect;
	int	n_exits;
}				t_merr;
/* merr - map_error */

typedef struct s_map
{
	int		width;
	int		height;
	char	**map_arr;
	int		pl_pos_x;
	int		pl_pos_y;
}				t_map;

int		check_arg(int argc, char **map);
void	check_map(int fd, t_map *map);

void	map_parser(int argc, char **map_path, t_map *map);

void	map_opt_init(t_mchk	*opt);
void	map_err_init(t_merr *err);

#endif //MAP_H
