/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 11:18:24 by celadia           #+#    #+#             */
/*   Updated: 2022/04/22 11:18:24 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# define SHIFT 4
# define STAT_ARR 8
# define PLAYER_ARR 9

# define PLAYER_IMG_0 "sprites/Pac-Man/pac_closed.xpm"
# define PLAYER_IMG_1 "sprites/Pac-Man/pac_open_left.xpm"
# define PLAYER_IMG_2 "sprites/Pac-Man/pac_open_down.xpm"
# define PLAYER_IMG_3 "sprites/Pac-Man/pac_open_right.xpm"
# define PLAYER_IMG_4 "sprites/Pac-Man/pac_open_up.xpm"
# define PLAYER_IMG_5 "sprites/Pac-Man/pac_semi_left.xpm"
# define PLAYER_IMG_6 "sprites/Pac-Man/pac_semi_down.xpm"
# define PLAYER_IMG_7 "sprites/Pac-Man/pac_semi_right.xpm"
# define PLAYER_IMG_8 "sprites/Pac-Man/pac_semi_up.xpm"

# define GHOST1_IMG_0 "sprites/Ghosts/R/ghost_down1.xpm"
# define GHOST1_IMG_1 "sprites/Ghosts/R/ghost_left1.xpm"
# define GHOST1_IMG_2 "sprites/Ghosts/R/ghost_down1.xpm"
# define GHOST1_IMG_3 "sprites/Ghosts/R/ghost_right1.xpm"
# define GHOST1_IMG_4 "sprites/Ghosts/R/ghost_up1.xpm"
# define GHOST1_IMG_5 "sprites/Ghosts/R/ghost_left2.xpm"
# define GHOST1_IMG_6 "sprites/Ghosts/R/ghost_down2.xpm"
# define GHOST1_IMG_7 "sprites/Ghosts/R/ghost_right2.xpm"
# define GHOST1_IMG_8 "sprites/Ghosts/R/ghost_up2.xpm"

# define GHOST2_IMG_0 "sprites/Ghosts/O/ghost_down1.xpm"
# define GHOST2_IMG_1 "sprites/Ghosts/O/ghost_left1.xpm"
# define GHOST2_IMG_2 "sprites/Ghosts/O/ghost_down1.xpm"
# define GHOST2_IMG_3 "sprites/Ghosts/O/ghost_right1.xpm"
# define GHOST2_IMG_4 "sprites/Ghosts/O/ghost_up1.xpm"
# define GHOST2_IMG_5 "sprites/Ghosts/O/ghost_left2.xpm"
# define GHOST2_IMG_6 "sprites/Ghosts/O/ghost_down2.xpm"
# define GHOST2_IMG_7 "sprites/Ghosts/O/ghost_right2.xpm"
# define GHOST2_IMG_8 "sprites/Ghosts/O/ghost_up2.xpm"

# define WALL_IMG "sprites/Other/Walls/wall.xpm"
# define EMPTY_IMG "sprites/Other/Walls/black.xpm"
# define COL_IMG "sprites/Other/Pacdots/pacdot_food.xpm"
# define EXIT_OPEN "sprites/Other/Portal/portal_open.xpm"
# define EXIT_CLOSE "sprites/Other/Portal/portal_close.xpm"

typedef struct s_image
{
	int		width;
	int		height;
	void	*img_ptr;
}				t_img;

typedef struct s_sprites
{
	t_img	*stat_img[STAT_ARR];
	t_img	*pl_anim[PLAYER_ARR];
	t_img	*gh1_anim[PLAYER_ARR];
	t_img	*gh2_anim[PLAYER_ARR];
}				t_spr;
/* spr - sprites */

void	sprite_init(t_spr *spr, void *mlx_ptr);

#endif //SPRITE_H
