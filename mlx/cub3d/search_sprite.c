/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:31:43 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/27 18:02:32 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char*	give_color_sprite(t_cub *cub, double kall, double hit)
{
	return(cub->sp.add_texture + (int)kall * cub->sp.size_line
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

	hit = cub->sp.width * (i - point_sprite) / size;
	j = 0;
	kall = 0;
	j = (cub->height - size) / 2;
	max = (cub->height + size) / 2;
 	if (j < 0)
    {
        kall = (double)cub->sp.height / (double)size * (-j);
        j = 0;
        max = cub->height;
    }
	while (j < max)
	{
		color = *(unsigned int*)give_color_sprite(cub, kall, hit);
		if (color != 0)
			my_mlx_pixel_put(i, j, color, cub);
		j++;
		kall += (double)cub->sp.height / (double)size;
		
	}
}