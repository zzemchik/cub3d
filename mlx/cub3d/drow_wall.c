/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:35:13 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/10 19:41:11 by rnancee          ###   ########.fr       */
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

static int	tx_width(t_cub *cub)
{
	if (cub->what_texture == 0)
		return (cub->no.width);
	if (cub->what_texture == 1)
		return (cub->so.width);
	if (cub->what_texture == 2)
		return (cub->ea.width);
	if (cub->what_texture == 3)
		return (cub->we.width);
	return (0);
}

static int	tx_height(t_cub *cub)
{
	if (cub->what_texture == 0)
		return (cub->no.height);
	if (cub->what_texture == 1)
		return (cub->so.height);
	if (cub->what_texture == 2)
		return (cub->ea.height);
	if (cub->what_texture == 3)
		return (cub->we.height);
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
		if (color != 0)
			my_mlx_pixel_put(i, j, color, cub);
		else
			my_mlx_pixel_put(i, j, cub->color_floor, cub);
		j++;
		wall->kall += (double)tx_height(cub) / (double)wall->h_wall;
	}
	j--;
	while (j++ < cub->height)
		my_mlx_pixel_put(i, j, cub->color_floor, cub);
}

void		drow_wall(t_cub *cub, int i)
{
	int				j;
	t_draw_wall		wall;

	wall.hit = cub->hit * tx_width(cub);
	j = 0;
	wall.kall = 0;
	wall.h_wall = cub->width / 2;
	wall.h_wall = ceil((wall.h_wall / tan(M_PI / 6)) / (cub->dist_wall * \
	cos(cub->fov - cub->direction)));
	j = (cub->height - wall.h_wall) / 2;
	wall.max = (cub->height + wall.h_wall) / 2;
	if (j < 0)
	{
		wall.kall = (double)tx_height(cub) / (double)wall.h_wall * (-j);
		j = 0;
		wall.max = cub->height;
	}
	drow_wall_norm(cub, i, &wall, j);
}
