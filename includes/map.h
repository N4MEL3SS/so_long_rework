#ifndef MAP_H
# define MAP_H

# define CHAR_ARR_SIZE 6

# define COL_INDEX 0
# define EMPTY_INDEX 1
# define WALL_INDEX 2
# define EXIT_INDEX_CL 3
# define PLAYER_INDEX 4
# define GHOST1_INDEX 5
# define GHOST2_INDEX 6
# define EXIT_INDEX_OP 7

/* index = (char - 47 + (char / 69) % 10 */
/* opt_arr[0] = Collect (C)				 */
/* opt_arr[1] = Empty (1) 				 */
/* opt_arr[2] = Wall (0) 				 */
/* opt_arr[3] = Exit (E) 				 */
/* opt_arr[4] = Player (P) 				 */
/* opt_arr[5] = Ghost (G) 				 */

typedef struct s_map_check
{
	int		row;
	int		col;
	int		char_arr[CHAR_ARR_SIZE];
	int		fl_line;
	int		ex_pos_x;
	int		ex_pos_y;
}				t_mchk;
/* first or last line flag */
/* mchk - map_check_option */

typedef struct s_map_err
{
	int	rowlen;
	int	borders;
	int	n_players;
	int	n_collect;
	int	n_exits;
	int	n_ghost;
}				t_merr;
/* merr - map_error */

typedef struct s_map
{
	int		col;
	int		row;
	char	**arr;
	int		ex_pos_x;
	int		ex_pos_y;
}				t_map;
/* pl_pos - player position */

void	map_opt_init(t_mchk	*opt);
void	map_err_init(t_merr *err);

#endif //MAP_H
