/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:31:43 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/26 18:46:44 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char*	give_color_sprite(t_cub *cub, double kall, double hit)
{
	return(cub->texture_add_sprite + (int)kall * cub->size_line_tspr
	+ (int)hit * (cub->bpp / 8));
}

void d(t_cub *cub, int i, int size, int point_sprite)
{
int			j;
	double		h_wall;
	unsigned int color;
	char 		*xpm_data;
	double	kall;
	double max;
	double hit;

	hit = cub->width_texture_sprite * (i - point_sprite) / size;
	j = 0;
	kall = 0;
	j = (cub->height - size) / 2;
	max = (cub->height + size) / 2;
 	if (j < 0)
    {
        kall = (double)cub->height_texture_sprite / (double)size * (-j);
        j = 0;
        max = cub->height;
    }
	
	while (j < max)
	{
		color = *(unsigned int*)give_color_sprite(cub, kall, hit);
		if (color != 0)
			my_mlx_pixel_put(i, j, color, cub);
		j++;
		kall += (double)cub->height_texture_sprite / (double)size;
		
	}
	// printf("%f, %d\n", kall, point_sprite);
}