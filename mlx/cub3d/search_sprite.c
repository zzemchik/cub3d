/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 18:31:43 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/12 14:15:28 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char			*give_c(t_cub *cub, double y_texture, double x_texture)
{
	return (cub->sp.add_texture + (int)y_texture * cub->sp.size_line
	+ (int)x_texture * (cub->bpp / 8));
}

static void			drow_sprite_tx_norm(t_cub *cub, int size, t_sprite_tx tx)
{
	while (tx.j < tx.max)
	{
		tx.color = \
		*(unsigned int*)give_c(cub, tx.y_texture, tx.x_texture);
		if (tx.color != 0)
			my_mlx_pixel_put(tx.i, tx.j, tx.color, cub);
		tx.j++;
		tx.y_texture += (double)cub->sp.height / (double)size;
	}
}

void				drow_sprite_tx(t_cub *cub, int size, \
int point_sprite, double dist_sprite)
{
	t_sprite_tx		tx;

	tx.max = (cub->height + size) / 2;
	tx.i = point_sprite;
	tx.j = (cub->height - size) / 2;
	tx.y_texture = 0;
	if (tx.j < 0)
	{
		tx.y_texture = (double)cub->sp.height / (double)size * (-tx.j);
		tx.j = 0;
		tx.max = cub->height;
	}
	while (tx.i < point_sprite + size && tx.i < cub->width)
	{
		if (tx.i >= 0)
		{
			if (cub->dist_wall_all[tx.i] <= dist_sprite && ++tx.i)
				continue;
			tx.x_texture = cub->sp.width * (tx.i - point_sprite) / size;
			drow_sprite_tx_norm(cub, size, tx);
		}
		tx.i++;
	}
}
