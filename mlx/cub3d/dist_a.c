/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:29:23 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/10 19:55:57 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	dist_a_norm(t_cub *cub, t_ray *ray, int num_tx, int min)
{
	if (cub->map[(int)floor(ray->yy)][(int)floor(ray->xx + min * EPS)] == '1')
	{
		if (cub->fov < 3 * M_PI / 2 && cub->fov >= M_PI / 2)
		{
			cub->what_texture = num_tx;
			cub->hit = ray->yy - floor(ray->yy);
		}
		else
		{
			cub->what_texture = num_tx + 1;
			cub->hit = ceil(ray->yy) - ray->yy;
		}
		return (1);
	}
	return (0);
}

static void	dist_a_norm_1(t_cub *cub, t_ray *ray, int min, int *uu)
{
	if (*(uu) == 0)
	{
		cub->sprite_x[*uu] = (int)floor(ray->xx + min * EPS);
		cub->sprite_y[*uu] = (int)floor(ray->yy);
		(*uu)++;
	}
	else
	{
		ray->iter = 1;
		while ((*uu) - ray->iter >= 0 && \
		(!(cub->sprite_x[*uu - ray->iter] == (int)floor(ray->xx + min * EPS) \
		&& cub->sprite_y[*uu - ray->iter] == (int)floor(ray->yy))))
			ray->iter++;
		if ((*uu) - ray->iter == -1)
		{
			cub->sprite_x[*uu] = (int)floor(ray->xx + min * EPS);
			cub->sprite_y[*uu] = (int)floor(ray->yy);
			(*uu)++;
		}
	}
}

int			dist_a(t_cub *cub, t_ray *ray, int *uu)
{
	if (cub->fov < 3 * M_PI / 2 && cub->fov > M_PI / 2)
		ray->xx -= ray->dx;
	else
		ray->xx += ray->dx;
	if (cub->fov < 2 * M_PI && cub->fov > M_PI)
		ray->yy -= ray->a_1;
	else
		ray->yy += ray->a_1;
	if (dist_a_norm(cub, ray, 0, -1) == 1)
		return (1);
	if (dist_a_norm(cub, ray, 2, 1) == 1)
		return (1);
	if (cub->map[(int)floor(ray->yy)][(int)floor(ray->xx - EPS)] == '2')
		dist_a_norm_1(cub, ray, -1, uu);
	else if (cub->map[(int)floor(ray->yy)][(int)floor(ray->xx + EPS)] == '2')
		dist_a_norm_1(cub, ray, 1, uu);
	return (0);
}
