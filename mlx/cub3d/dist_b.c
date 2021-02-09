/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 14:30:25 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/09 19:27:32 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	dist_b_norm(t_cub *cub, t_ray *ray, int num_tx, int min)
{
	if (cub->map[(int)floor(ray->yy + min * EPS)][(int)floor(ray->xx)] == '1')
	{
		if (cub->fov < M_PI && cub->fov >= 0)
		{
			cub->what_texture = num_tx;
			cub->hit = ceil(ray->xx) - ray->xx;
		}
		else
		{
			cub->what_texture = num_tx + 1;
			cub->hit = ray->xx - floor(ray->xx);
		}
		return (1);
	}
	return (0);
}

static void	dist_b_norm_1(t_cub *cub, t_ray *ray, int min, int *ll)
{
	if (*(ll) == 0)
	{
		cub->sprite_x[*(ll)] = (int)floor(ray->xx);
		cub->sprite_y[*(ll)] = (int)floor(ray->yy + min * EPS);
		(*ll)++;
	}
	else
	{
		ray->iter = 1;
		while (*(ll) - ray->iter >= 0 && \
		(!(cub->sprite_x[*(ll) - ray->iter] == (int)floor(ray->xx) && \
		cub->sprite_y[*(ll) - ray->iter] == (int)floor(ray->yy + min * EPS))))
			ray->iter++;
		if (*(ll) - ray->iter == -1)
		{
			cub->sprite_x[*(ll)] = (int)floor(ray->xx);
			cub->sprite_y[*(ll)] = (int)floor(ray->yy + min * EPS);
			(*ll)++;
		}
	}
}

int			dist_b(t_cub *cub, t_ray *ray, int *ll)
{
	if (cub->fov < 3 * M_PI / 2 && cub->fov > M_PI / 2)
		ray->xx -= ray->b_1;
	else
		ray->xx += ray->b_1;
	if (cub->fov < 2 * M_PI && cub->fov > M_PI)
		ray->yy -= ray->dy;
	else
		ray->yy += ray->dy;
	if (dist_b_norm(cub, ray, 0, -1) == 1)
		return (1);
	if (dist_b_norm(cub, ray, 2, 1) == 1)
		return (1);
	if (cub->map[(int)floor(ray->yy - EPS)][(int)floor(ray->xx)] == '2')
		dist_b_norm_1(cub, ray, -1, ll);
	else if (cub->map[(int)floor(ray->yy + EPS)][(int)floor(ray->xx)] == '2')
	{
		dist_b_norm_1(cub, ray, 1, ll);
	}
	return (0);
}
