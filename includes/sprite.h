#ifndef SPRITES_H
# define SPRITES_H

# define IMG_SIZE 32
# define STAT_IMG 5

# define IMG_PATH "/Users/celadia/school21/so_long_rework/"

# define PLAYER_IMG "sprites/Pac-Man/pac_closed.xpm"
# define PLAYER2_IMG "sprites/Pac-Man/pac_open_right.xpm"
# define WALL_IMG "sprites/Other/Walls/wall.xpm"
# define EMPTY_IMG "sprites/Other/Walls/black.xpm"
# define COL_IMG "sprites/Other/Pacdots/pacdot_food.xpm"
# define EXIT_IMG "sprites/Other/Portal/portal.xpm"

typedef struct s_image
{
	int		width;
	int		height;
	void	*img_ptr;
}				t_img;

typedef struct s_sprites
{
	t_img	*stat_img[STAT_IMG];
	t_img	*player_img;
	t_img	*player2_img;
}				t_spr;
/* spt - sprites */

#endif //SPRITES_H
