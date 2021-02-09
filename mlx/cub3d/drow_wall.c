/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:35:13 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/09 16:50:07 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*give_color(t_cub *cub, double kall, double hit)
{
	if (cub->what_texture == 0)
		return (cub->no.add_texture + (int)kall * \
		cub->no.size_line + (int)hit * (cub->bpp / 8));
		if (cub->what_texture == 1)
		return (cub->so.add_texture + (int)kall * \
		cub->so.size_line + (int)hit * (cub->bpp / 8));
		if (cub->what_texture == 2)
		return (cub->ea.add_texture + (int)kall * \
		cub->ea.size_line + (int)hit * (cub->bpp / 8));
		if (cub->what_texture == 3)
		return (cub->we.add_texture + (int)kall * \
		cub->we.size_line + (int)hit * (cub->bpp / 8));
		return (0);
}

static void	drow_wall_norm(t_cub *cub, int i, t_draw_wall *wall, int j)
{
	int		f;
	double	color;

	f = j + 1;
	while (--f > -1)
		my_mlx_pixel_put(i, f, cub->color_ceil, cub);
	while (j < wall->max)
	{
		color = *(unsigned int*)give_color(cub, wall->kall, wall->hit);
		my_mlx_pixel_put(i, j, color, cub);
		j++;
		wall->kall += (double)cub->no.height / (double)wall->h_wall;
	}
	j--;
	while (j++ < cub->height)
		my_mlx_pixel_put(i, j, cub->color_floor, cub);
}

void		drow_wall(t_cub *cub, int i)
{
	int				j;
	t_draw_wall		wall;

	wall.hit = cub->hit * cub->no.width;
	j = 0;
	wall.kall = 0;
	wall.h_wall = cub->height / 2;
	wall.h_wall = ceil((wall.h_wall / tan(M_PI / 6)) / (cub->dist_wall * \
	cos(cub->fov - cub->direction)));
	j = (cub->height - wall.h_wall) / 2;
	wall.max = (cub->height + wall.h_wall) / 2;
	if (j < 0)
	{
		wall.kall = (double)cub->no.height / (double)wall.h_wall * (-j);
		j = 0;
		wall.max = cub->height;
	}
	drow_wall_norm(cub, i, &wall, j);
}

double		map_wall(double x, double y, t_cub *cub)
{
	double	distance;
	int		i;
	int		j;

	if (j == floor(x))
		j = floor(x - 0.1);
	else
		j = floor(x);
	if (i == floor(y))
		i = floor(y - 0.1);
	else
		i = floor(y);
	if (j > 5)
		j = 5;
	if (i > 5)
		i = 5;
	if (i < 0)
		i = 0;
	if (j < 0)
		j = 0;
	distance = sqrt(pow(x - cub->x, 2) + pow(y - cub->y, 2));
	if (cub->map[i][j] == '1')
		return (distance);
	return (-1);
}
