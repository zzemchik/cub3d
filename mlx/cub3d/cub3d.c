/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:51:00 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/17 20:17:33 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int g_j;
int g_i;



void            my_mlx_pixel_put(int x, int y, unsigned int color, char *data, int size_line)
{
    char    *dst;
    dst = data + y * size_line + x * 4;
    *(unsigned int*)dst = color;
}

int exita()
{
    exit(0);
}





// int main () 
// {
// 	t_cub *cub;
// 	cub = (t_cub *)malloc(sizeof(t_cub));
// 	set_all(cub);
// 	int i = 0;
// 	int j = 0;
// 	int k = 0;
// 	int z = 0;
// 	char **line;
// 	g_i = 0;
// 	g_j = 0;
// 	line = (char **)malloc(7 * sizeof(char *));
// 	while (i != 6)
// 	{
// 		line[i] = (char *)malloc(9);
// 		i++;
// 	}
// 	line[0] = "111111";
// 	line[1] = "100001";
// 	line[2] = "100001";
// 	line[3] = "100001";
// 	line[4] = "1000N1";
// 	line[5] = "111111";
// 	line[6] = 0;
// 	i = 0;
// 	cub->map = line;

// 	while (g_i == 0 && line[i] != 0)
// 	{
// 		j = 0;
// 		while(line[i][j] && g_i == 0)
// 		{
// 			if (line[i][j] == 'N' || line[i][j] == 'E' ||
// 			line[i][j] == 'S' || line[i][j] == 'W')
// 			{
// 				cub->x = j + 0.5;
// 				cub->y = i + 0.5;
// 				g_i++;
// 				if (line[i][j] == 'N')
// 					cub->direction = 3 * M_PI / 2;
// 				else if (line[i][j] == 'E')
// 						cub->direction = 0;
// 				else if (line[i][j] == 'S')
// 					cub->direction = M_PI / 2;
// 				else if (line[i][j] == 'W')
// 					cub->direction = M_PI;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
//  	mlx_hook(cub->mlx_win, 2, 1L << 0, where_im, cub);
// 	mlx_hook(cub->mlx_win, 3, 1L << 1, where_im, cub);
//     mlx_hook(cub->mlx_win, 17, 1L << 17, exita, 0);
// 	mlx_loop_hook(cub->mlx, drowing_loop, cub);
//     mlx_loop(cub->mlx);
//     free(cub);
// }
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

	// while (i < 1199)
	//  {

	// 	 yy = cub->y;
	// 	 yy1 = cub->y;
	// 	 xx = cub->x;
	// 	 xx1 = cub->x;
	// 	while (1)
	// 	{	
	// 		if (dir >= 0 && dir < M_PI)
	// 		{
	// 			if (yy == cub->y)
	// 			{
	// 				yy = ceil(yy + 0.000001);
	// 				xx =cub->x + fabs(cub->y - yy) / tan((2 * M_PI - dir));				
	// 			}
	// 			else
	// 			{
	// 				yy += 1;
	// 				xx += 1 / tan((2 * M_PI - dir));
	// 			}
	// 		}
	// 		else
	// 		{
	// 			if (yy == cub->y)
	// 			{
	// 				yy = floor(yy - 0.000001);
	// 				xx = cub->x + fabs(cub->y - yy) / tan(2 * M_PI - dir);
	// 			}
	// 			else
	// 			{
	// 				yy -= 1;
	// 				xx += 1 / tan(2 * M_PI - dir);
	// 			}
	// 		}
	// 		if (dir >= M_PI / 2 && dir < 3 * M_PI / 2)
	// 			if (xx1 == cub->x)
	// 			{
	// 				xx1 = floor(xx1 - 0.000001);
	// 				yy1 =cub->y + fabs(cub->x - xx1) * tan(2 * M_PI - dir);
	// 			}
	// 			else
	// 			{
	// 				xx1 -= 1;
	// 				yy1 += tan(2 * M_PI - dir);
	// 			}
	// 		else
	// 			if (xx1 == cub->x)
	// 			{
	// 				xx1 = ceil(xx1 + 0.000001);
	// 				yy1 =cub->y + fabs(cub->x - xx1) * tan(2 * M_PI - dir);
	// 			}
	// 			else
	// 			{
	// 				xx1 += 1;
	// 				yy1 += tan(2 * M_PI - dir);
	// 			}
	// 		if (xx < 0 || yy < 0 || yy > 5 || xx > 5 || cub->map[(int)floor(yy - 0.000001)][(int)floor(xx)] == '1' || cub->map[(int)floor(yy + 0.000001)][(int)floor(xx)] == '1')
	// 			dist_wall_x = sqrt(pow(xx - cub->x, 2) + pow(yy - cub->y, 2));
	// 		if (xx1 < 0 || yy1 < 0 || yy1 > 5 || xx1 > 5 ||cub->map[(int)floor(yy1)][(int)floor(xx1 - 0.000001)] == '1' || cub->map[(int)floor(yy1)][(int)floor(xx1 + 0.000001)] == '1')
	// 			dist_wall_y = sqrt(pow(xx1 - cub->x, 2) + pow(yy1 - cub->y, 2));
	// 		if (dist_wall_x < dist_wall_y)
	// 		{
	// 			dist_wall = dist_wall_x;
	// 			break ;
	// 		}
	// 		if (dist_wall_x > dist_wall_y)
	// 		{
	// 			dist_wall = dist_wall_y;
	// 			break ;
	// 		}
	// }
	// 	i++;
	// 	drow_wall(dist_wall, cub, dir, i);
	// 	dir -= M_PI / 6 / cub->width;
	
	// }
// 		mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image, 0, 0);
// 	return (0);
// }