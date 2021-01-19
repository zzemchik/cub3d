/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:35:13 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/18 17:49:13 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	drow_wall(t_cub *cub, double dir, int i)
{
	int		j;
	double	h_wall;

	j = 0;
	cub->dist_wall = cub->dist_wall * cos(dir - cub->direction);
	h_wall = cub->height / 2;
	h_wall = h_wall / tan((60 / 2) * (M_PI / 180));
	h_wall = ceil(h_wall / cub->dist_wall);
	j = (cub->height - h_wall) / 2;
	if (h_wall > cub->width)
		h_wall = cub->width;
	while (j < (cub->height + h_wall) / 2)
	{
		if (j < 0)
			j = 0;
		if (j > cub->height)
			break ;
		my_mlx_pixel_put(i, j, 0x7000DD, cub);
		j++;
	}
}

double	map_wall(double x, double y, t_cub *cub)
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
