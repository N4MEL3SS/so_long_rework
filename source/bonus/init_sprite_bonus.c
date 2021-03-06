/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: celadia <celadia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:26:27 by celadia           #+#    #+#             */
/*   Updated: 2022/04/20 12:26:27 by celadia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_img	*img_init(void *mlx_ptr, char *path)
{
	t_img	*img;

	img = (t_img *)mem_alloc(sizeof(t_img));
	img->width = 0;
	img->height = 0;
	img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, path,
			&img->width, &img->height);
	return (img);
}

void	player_sprite_init(t_spr *spr, void *mlx_ptr)
{
	spr->pl_anim[0] = spr->stat_img[PLAYER_INDEX];
	spr->pl_anim[1] = img_init(mlx_ptr, PLAYER_IMG_1);
	spr->pl_anim[2] = img_init(mlx_ptr, PLAYER_IMG_2);
	spr->pl_anim[3] = img_init(mlx_ptr, PLAYER_IMG_3);
	spr->pl_anim[4] = img_init(mlx_ptr, PLAYER_IMG_4);
	spr->pl_anim[5] = img_init(mlx_ptr, PLAYER_IMG_5);
	spr->pl_anim[6] = img_init(mlx_ptr, PLAYER_IMG_6);
	spr->pl_anim[7] = img_init(mlx_ptr, PLAYER_IMG_7);
	spr->pl_anim[8] = img_init(mlx_ptr, PLAYER_IMG_8);
}

void	ghost1_sprite_init(t_spr *spr, void *mlx_ptr)
{
	spr->gh1_anim[0] = spr->stat_img[GHOST1_INDEX];
	spr->gh1_anim[1] = img_init(mlx_ptr, GHOST1_IMG_1);
	spr->gh1_anim[2] = img_init(mlx_ptr, GHOST1_IMG_2);
	spr->gh1_anim[3] = img_init(mlx_ptr, GHOST1_IMG_3);
	spr->gh1_anim[4] = img_init(mlx_ptr, GHOST1_IMG_4);
	spr->gh1_anim[5] = img_init(mlx_ptr, GHOST1_IMG_5);
	spr->gh1_anim[6] = img_init(mlx_ptr, GHOST1_IMG_6);
	spr->gh1_anim[7] = img_init(mlx_ptr, GHOST1_IMG_7);
	spr->gh1_anim[8] = img_init(mlx_ptr, GHOST1_IMG_8);
}

void	ghost2_sprite_init(t_spr *spr, void *mlx_ptr)
{
	spr->gh2_anim[0] = spr->stat_img[GHOST2_INDEX];
	spr->gh2_anim[1] = img_init(mlx_ptr, GHOST2_IMG_1);
	spr->gh2_anim[2] = img_init(mlx_ptr, GHOST2_IMG_2);
	spr->gh2_anim[3] = img_init(mlx_ptr, GHOST2_IMG_3);
	spr->gh2_anim[4] = img_init(mlx_ptr, GHOST2_IMG_4);
	spr->gh2_anim[5] = img_init(mlx_ptr, GHOST2_IMG_5);
	spr->gh2_anim[6] = img_init(mlx_ptr, GHOST2_IMG_6);
	spr->gh2_anim[7] = img_init(mlx_ptr, GHOST2_IMG_7);
	spr->gh2_anim[8] = img_init(mlx_ptr, GHOST2_IMG_8);
}

void	sprite_init(t_spr *spr, void *mlx_ptr)
{
	spr->stat_img[COL_INDEX] = img_init(mlx_ptr, COL_IMG);
	spr->stat_img[EMPTY_INDEX] = img_init(mlx_ptr, EMPTY_IMG);
	spr->stat_img[WALL_INDEX] = img_init(mlx_ptr, WALL_IMG);
	spr->stat_img[EXIT_INDEX_CL] = img_init(mlx_ptr, EXIT_CLOSE);
	spr->stat_img[PLAYER_INDEX] = img_init(mlx_ptr, PLAYER_IMG_0);
	spr->stat_img[GHOST1_INDEX] = img_init(mlx_ptr, GHOST1_IMG_0);
	spr->stat_img[GHOST2_INDEX] = img_init(mlx_ptr, GHOST2_IMG_0);
	spr->stat_img[EXIT_INDEX_OP] = img_init(mlx_ptr, EXIT_OPEN);
	player_sprite_init(spr, mlx_ptr);
	ghost1_sprite_init(spr, mlx_ptr);
	ghost2_sprite_init(spr, mlx_ptr);
}
