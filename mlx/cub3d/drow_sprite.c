/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:03:05 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/08 16:47:20 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_dist_sprite(t_cub *cub, int k)
{
	int i;
	int j;
	double h;
	int l;
	j = 0;
	i = 0;
	while (i < k)
	{
		h = cub->dist_sprite[i];
		j = i + 1;
		while (j < k)
		{
			if (h > cub->dist_sprite[j])
			{
				h = cub->dist_sprite[j];
				l = j;
			}
		j++;
		}
		if (h != cub->dist_sprite[i])
		{
			cub->dist_sprite[l] = cub->dist_sprite[i];
			cub->dist_sprite[i] = h;
            h = cub->sprite_x[i];
            cub->sprite_x[i] = cub->sprite_x[l];
            cub->sprite_x[l] = h;
            h = cub->sprite_y[i];
            cub->sprite_y[i] = cub->sprite_y[l];
            cub->sprite_y[l] = h;
		}
		i++;
	}
}
void			drow_sprite(t_cub *cub, int k)
{
    int     u;
    double  w_sprite;
    double  dir_sprite;
    int     point_sprite;
    int     size;
    u = 0;
    while (u < k)
    {
        cub->dist_sprite[u] = sqrt(pow(cub->x - 0.5 - cub->sprite_x[u], 2) + pow(cub->y - 0.5 - cub->sprite_y[u], 2));
        u++;
    }
    sort_dist_sprite(cub, k);
    u = 0;
    w_sprite = (double)(cub->width / 2) / tan(M_PI / 6);
    while (k--)
    {   
        dir_sprite = atan2(cub->sprite_y[k] - cub->y + 0.5, cub->sprite_x[k] - cub->x + 0.5) - cub->direction;
        dir_sprite = valid_pi(dir_sprite);
        size = w_sprite / (cos(dir_sprite) * cub->dist_sprite[k]);
        point_sprite = cub->width / 2 + tan(dir_sprite) * w_sprite - size / 2;
        if (size <= 0 || point_sprite >= cub->width)
            continue ;
        d(cub, size, point_sprite, cub->dist_sprite[k]);
    }
}
