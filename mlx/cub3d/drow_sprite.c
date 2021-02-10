/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:03:05 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/10 20:57:54 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	sort_dist_sprite_norm(t_cub *cub, int k, double *h, int i)
{
	int		j;
	int		l;

	j = i;
	l = 0;
	*h = cub->dist_sprite[i];
	while (j++ < k)
		if (*h > cub->dist_sprite[j])
		{
			*h = cub->dist_sprite[j];
			l = j;
		}
	return (l);
}

static void	sort_dist_sprite(t_cub *cub, int k)
{
	int		i;
	double	h;
	int		l;

	i = -1;
	while (i++ < k)
	{
		l = sort_dist_sprite_norm(cub, k, &h, i);
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
	}
}

void		drow_sprite(t_cub *cub, int k)
{
	int		u;
	double	w_sprite;
	double	dir_sprite;
	int		point_sprite;
	int		size;

	u = -1;
	while (u++ < k)
		cub->dist_sprite[u] = sqrt(pow(cub->x - 0.5 - cub->sprite_x[u], 2) \
		+ pow(cub->y - 0.5 - cub->sprite_y[u], 2));
	sort_dist_sprite(cub, k);
	u = 0;
	w_sprite = (double)(cub->width / 2) / tan(M_PI / 6);
	while (k--)
	{
		dir_sprite = atan2(cub->sprite_y[k] - cub->y + 0.5, \
		cub->sprite_x[k] - cub->x + 0.5) - cub->direction;
		dir_sprite = valid_pi(dir_sprite);
		size = w_sprite / (cos(dir_sprite) * cub->dist_sprite[k]);
		point_sprite = (double)cub->width / 2 + tan(dir_sprite) * w_sprite - (double)size / 2;
		if (size <= 0 || point_sprite >= cub->width)
			continue ;
		drow_sprite_tx(cub, size, point_sprite, cub->dist_sprite[k]);
	}
}
