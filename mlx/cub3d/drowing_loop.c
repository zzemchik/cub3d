/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowing_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:02:40 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/14 17:18:12 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	norm_drowing_loop(double xx, double yy, t_cub *cub, int *i)
{
	double t;

	t = 0;
	while (t += 0.005)
	{
		xx = cub->x + t * cos(cub->direction + cub->fov);
		yy = cub->y + t * sin(cub->direction + cub->fov);
		if ((cub->dist_wall = map_wall(xx, yy, cub)) > 0 && (*i)++)
		{
			drow_wall(cub, cub->fov, *i);
			break ;
		}
		if (*i > cub->width - 1)
			break ;
	}
}

int			drowing_loop(t_cub *cub)
{
	int		i;
	double	xx;
	double	yy;

	color_floor_roof(cub);
	cub->fov = M_PI / 6;
	i = -1;
	while (cub->fov > -M_PI / 6)
	{
		norm_drowing_loop(xx, yy, cub, &i);
		cub->fov -= M_PI / 6 / cub->width;
	}
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image, 0, 0);
	return (0);
}
