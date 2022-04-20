#ifndef SPRITE_H
# define SPRITE_H

# define SHIFT 4
# define STAT_ARR 7
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

# define WALL_IMG "sprites/Other/Walls/wall.xpm"
# define EMPTY_IMG "sprites/Other/Walls/black.xpm"
# define COL_IMG "sprites/Other/Pacdots/pacdot_food.xpm"
# define EXIT_OPEN "sprites/Other/Portal/portal_open.xpm"
# define EXIT_CLOSE "sprites/Other/Portal/portal_close.xpm"
# define GHOST_IMG "sprites/Ghosts/Y/ghost_down1.xpm"

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
}				t_spr;
/* spr - sprites */

void	sprite_init(t_spr *spr, void *mlx_ptr);

#endif //SPRITE_H
