/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:19:17 by celadia           #+#    #+#             */
/*   Updated: 2022/04/22 11:19:17 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# define UP 4
# define DOWN 2
# define LEFT 1
# define RIGHT 3
# define CENTER 0

# define PL_SPEED 4
# define GH1_SPEED 2
# define GH2_SPEED 2
# define KEY_ARR_SIZE 5
/* SPEED_P - Positive */
/* SPEED_N - Negative */

typedef struct s_player
{
	int		win_pos_x;
	int		win_pos_y;
	int		vector;
	int		n_vector;
	int		collect;
	int		move_count;
	int		key_array[KEY_ARR_SIZE];
}				t_play;
/* env - environment */
/* pl - player */

#endif //PLAYER_H
