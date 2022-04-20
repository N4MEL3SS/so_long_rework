#ifndef PLAYER_H
# define PLAYER_H

# define UP 4
# define DOWN 2
# define LEFT 1
# define RIGHT 3
# define CENTER 0

# define SPEED 4
# define KEY_ARR_SIZE 5
/* SPEED_P - Positive */
/* SPEED_N - Negative */

typedef struct s_player
{
	int		pos_x;
	int		pos_y;
	int		vector;
	int		n_vector;
	int		score;
	int		collect;
	int		move_count;
	int		key_array[KEY_ARR_SIZE];
}				t_play;
/* env - environment */
/* pl - player */

#endif //PLAYER_H
