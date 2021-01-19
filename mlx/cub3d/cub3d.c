/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:51:00 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/18 15:54:45 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int g_j;
int g_i;



void            my_mlx_pixel_put(int x, int y, unsigned int color, t_cub *cub)
{
    char    *dst;
	if (x < 0 || y < 0 || x >= cub->width || y >= cub->height)
		return ;
    dst = cub->data + y * cub->size_line + x * 4;
    *(unsigned int*)dst = color;
}

int exita()
{
    exit(0);
}

int main () 
{
	t_cub *cub;
	int i;
	int j;
	g_error = 0;
	cub = malloc(sizeof(t_cub));
	cub->par = malloc(sizeof(t_parser));
	all_set(cub);
 	if (g_error != 0)
	{
		all_free(cub);
		printf("Error");
		exit(0);
	}
	g_i = 0;
	g_j = 0;

	while (g_i == 0 && cub->map[i] != 0)
	{
		j = 0;
		while(cub->map[i][j] && g_i == 0)
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'E' ||
			cub->map[i][j] == 'S' || cub->map[i][j] == 'W')
			{
				cub->x = j + 0.5;
				cub->y = i + 0.5;
				g_i++;
				if (cub->map[i][j] == 'N')
					cub->direction = 3 * M_PI / 2;
				else if (cub->map[i][j] == 'E')
						cub->direction = 0;
				else if (cub->map[i][j] == 'S')
					cub->direction = M_PI / 2;
				else if (cub->map[i][j] == 'W')
					cub->direction = M_PI;
			}
			j++;
		}
		i++;
	}
	
 	mlx_hook(cub->mlx_win, 2, 1L << 0, where_im, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 1, where_im, cub);
    mlx_hook(cub->mlx_win, 17, 1L << 17, exita, 0);
	mlx_loop_hook(cub->mlx, drowing_loop, cub);
    mlx_loop(cub->mlx);
    all_free(cub);
}
	//mini_map

	// while (cub->map[i])
	// {
	// 	j = 0;
	// 	while(cub->map[i][j])
	// 	{
	// 		if (cub->map[i][j] == '1')
	// 			{
	// 			x = 0;
	// 			while (x < 200)
	// 				{
	// 				y = 0;
	// 				while (y < 200)
	// 				{
	// 					my_mlx_pixel_put(i * 200 + x, j * 200 + y, 0x3431fe, cub->data, cub->size_line);
	// 					y++;
	// 				}
	// 				x++;
	// 				}
	// 			}
	// 		j++;
	// 	}
	// i++;
	// }
	// i = cub->x * 200;
	// while (i < cub->x * 200 + 15)
	// { 
	// 	j = cub->y * 200;
	// 	while (j < cub->y * 200 + 15)
	// 	{
	// 		my_mlx_pixel_put(i, j, 0x34F800, cub->data, cub->size_line);
	// 		my_mlx_pixel_put(cub->x * 200 - (i - cub->x * 200), j, 0x34F800, cub->data, cub->size_line);
	// 		my_mlx_pixel_put(i, cub->y * 200 - (j - cub->y * 200), 0x34F800, cub->data, cub->size_line);
	// 		my_mlx_pixel_put(cub->x * 200 - (i - cub->x * 200), cub->y * 200 - (j - cub->y * 200), 0x34F800, cub->data, cub->size_line);
	// 		j++;
	// }
	// 	i++;
	// }

	// mini cub

// int drowing_loop(t_cub *cub)
// {
// 	int i;
// 	double dist_wall;
// 	double dist_wall_y;
// 	double dist_wall_x;
// 	double xx;
// 	double yy;
// 	double xx1;
// 	double yy1;
// 	double dir;
// 	int q = 0;
// 	double t;
// 	color_floor_roof(cub);
// 	dir = M_PI / 6;
	
// 	i = -1;
//  	while (dir > -M_PI / 6)
// 	 {
// 		t = 0;
// 		while (1)
// 		{
			
// 			xx = cub->x + t * cos(cub->direction + dir);
// 			yy = cub->y + t * sin(cub->direction + dir);
// 			if ((dist_wall = map_wall(xx, yy, cub)) > 0)
// 			{
// 			i++;
// 			drow_wall(dist_wall, cub, dir, i);
// 				break;
// 			}
// 			if (i > cub->width - 1)
// 					break;
// 			t += 0.005;
// 		}
// 		dir -= M_PI / 6 / cub->width;
	
// 	}
// 	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image, 0, 0);
// 	return (0);
// }

