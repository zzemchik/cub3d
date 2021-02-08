/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:31:43 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/08 16:48:44 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char*	give_color_sprite(t_cub *cub, double y_texture, double x_texture)
{
	return(cub->sp.add_texture + (int)y_texture * cub->sp.size_line
	+ (int)x_texture * (cub->bpp / 8));
}

void d(t_cub *cub, int size, int point_sprite, double dist_sprite)
{
	int				j;
	unsigned int	color;
	double			y_texture;
	double			max;
	double			x_texture;
	int				i;

	j = 0;
	y_texture = 0;
	j = (cub->height - size) / 2;
	max = (cub->height + size) / 2;
	i = point_sprite;
	while (i < point_sprite + size && i < cub->width)
	{	
		if (i >= 0)
		{
			if (cub->dist_wall_all[i] <= dist_sprite && ++i)
				continue;
			x_texture = cub->sp.width * (i - point_sprite) / size;
			j = (cub->height - size) / 2;
			y_texture = 0;
			if (j < 0)
			{
				y_texture = (double)cub->sp.height / (double)size * (-j);
				j = 0;
				max = cub->height;
			}
			while (j < max)
			{
				color = *(unsigned int*)give_color_sprite(cub, y_texture, x_texture);
				if (color != 0)
					my_mlx_pixel_put(i, j, color, cub);
				j++;
				y_texture += (double)cub->sp.height / (double)size;
			}
		}
		i++;
	}
}