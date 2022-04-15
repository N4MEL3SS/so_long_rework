#ifndef MAP_H
# define MAP_H

# define CHAR_ARR_SIZE 5
# define MAX_MAP 10

# define COLLECT_INDEX 0
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

typedef struct s_map_check
{
	int		row;
	int		col;
	int		char_arr[CHAR_ARR_SIZE];
	int		fl_line; /* first or last line flag */
}				t_mchk; /* mopt - map_check_option */

typedef struct s_map_err
{
	int	rowlen;
	int	borders;
	int	symbols;
	int	way;
	int	n_players;
	int	n_ghosts;
	int	n_collect;
	int	n_exits;
}				t_merr; /* merr - map_error */

typedef struct s_map
{
	int		col[MAX_MAP];
	int		row[MAX_MAP];
	int		map_count;
	char	**map;
	char	**map_path;
}				t_map;

int		*check_arg(int argc, char **map);
void	check_map(int *fd, t_mchk *opt, t_map *map);

void	map_opt_init(t_mchk	*opt);
void	map_err_init(t_merr *err);
void	map_init(t_map *map);

#endif //MAP_H
