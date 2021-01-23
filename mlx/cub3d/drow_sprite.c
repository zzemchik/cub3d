/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:03:05 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/23 20:26:45 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void drow_sprite(t_cub *cub,int i)
{
	// 	int			j;
	// double		h_wall;
	// unsigned int color;
	// char 		*xpm_data;
	// double	kall;
	// double max;
	// double hit;

	// hit = cub->hit_sprite * cub->width_texture;
	// j = 0;
	// kall = 0;
	// cub->dist_sprite = cub->dist_sprite * cos(cub->fov - cub->direction);
	// h_wall = cub->height / 2;
	// h_wall = h_wall / tan((60 / 2) * (M_PI / 180));
	// h_wall = ceil(h_wall / cub->dist_sprite);
	// j = (cub->height - h_wall) / 2;
	// max = (cub->height + h_wall) / 2;
 	// if (j < 0)
    // {
    //     kall = (double)cub->height_texture / (double)h_wall * (-j);
    //     j = 0;
    //     max = cub->height;
    // }
	// while (j < max)
	// {
	// 	color = *(unsigned int*)give_color(cub,  kall, hit);
	// 	my_mlx_pixel_put(i, j, color, cub);
	// 	j++;
	// 	kall += (double)cub->height_texture / (double)h_wall;
	// }
	// cub->dist_sprite = 0;
}