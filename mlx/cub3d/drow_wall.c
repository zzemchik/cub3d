/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:35:13 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/29 15:58:34 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char*	give_color(t_cub *cub, double kall, double hit)
{
	if (cub->what_texture == 0)
		return(cub->no.add_texture + (int)kall * cub->no.size_line \
		+ (int)hit * (cub->bpp / 8));
	if (cub->what_texture == 1)
		return(cub->so.add_texture + (int)kall * cub->so.size_line \
		+ (int)hit * (cub->bpp / 8));
	if (cub->what_texture == 2)
		return(cub->ea.add_texture + (int)kall * cub->ea.size_line \
		+ (int)hit * (cub->bpp / 8));
	if (cub->what_texture == 3)
		return(cub->we.add_texture + (int)kall * cub->we.size_line \
		+ (int)hit * (cub->bpp / 8));
	return (0);
}
void	drow_wall(t_cub *cub, int i)
{
	int			j;
	int f;
	double		h_wall;
	unsigned int color;
	char 		*xpm_data;
	double	kall;
	double max;
	double hit;

	hit = cub->hit * cub->no.width;
	j = 0;
	kall = 0;
	h_wall = cub->height / 2;
	h_wall = ceil((h_wall / tan(M_PI / 6)) / (cub->dist_wall * cos(cub->fov - cub->direction)));
	j = (cub->height - h_wall) / 2;
	max = (cub->height + h_wall) / 2;
 	if (j < 0)
    {
        kall = (double)cub->no.height / (double)h_wall * (-j);
        j = 0;
        max = cub->height;
    }
	f = j + 1;
	while (--f > -1)
		my_mlx_pixel_put(i, f, cub->color_ceil, cub);
	while (j < max)
	{
		color = *(unsigned int*)give_color(cub,  kall, hit);
		my_mlx_pixel_put(i, j, color, cub);
		j++;
		kall += (double)cub->no.height / (double)h_wall;
	}
	j--;
	while (j++ < cub->height)
		my_mlx_pixel_put(i, j, cub->color_floor, cub);
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
