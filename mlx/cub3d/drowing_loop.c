/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowing_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:02:40 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/18 17:42:26 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	norm_drowing_loop(double xx, double yy, t_cub *cub, int *i)
{

}

int			drowing_loop(t_cub *cub)
{
	int		i;
	double	xx;
	double	yy;
	double	dx;
	double	dy;
	double	b_1;
	double	a_1;
	double	a_gip;
	double	b_gip;

	color_floor_roof(cub);
	 cub->fov = cub->direction - M_PI / 6;
    
    i = -1;
    while (++i < cub->width)
    {
        cub->fov = valid_pi(cub->fov);
            xx = cub->x;
            yy = cub->y;
        while (1)
        {
            if (cub->fov < 2 * M_PI && cub->fov > M_PI)
                dy = yy - floor(yy - 0.000001);
            else
                dy = ceil(yy + 0.000001) - yy;
            if (cub->fov < 3 * M_PI / 2 && cub->fov > M_PI / 2)
                dx = xx - floor(xx - 0.000001);
            else
                dx = ceil(xx + 0.000001) - xx;
            if ((cub->fov > 0 && cub->fov < M_PI / 2) || (cub->fov > M_PI && cub->fov < 3 * M_PI / 2))
            {
                a_1 = tan(fmod(cub->fov, M_PI / 2)) * dx;
                b_1 = tan(M_PI / 2 - fmod(cub->fov, M_PI / 2)) * dy;
            }
            else
            {
                b_1 = tan(fmod(cub->fov, M_PI / 2)) * dy;
                a_1 = tan(M_PI / 2 - fmod(cub->fov, M_PI / 2)) * dx;
            }

            b_gip = sqrt(pow(b_1, 2) + pow(dy, 2));
            a_gip = sqrt(pow(a_1, 2) + pow(dx, 2));
            if (b_gip > a_gip)
            {
                if (cub->fov < 3 * M_PI / 2 && cub->fov > M_PI / 2)
                    xx -= dx;
                else
                    xx += dx;
                if (cub->fov < 2 * M_PI && cub->fov > M_PI)
                    yy -= a_1;
                else
                    yy += a_1;

                if (cub->map[(int)floor(yy)][(int)floor(xx - 0.000001)] == '1')
                    break;
                if (cub->map[(int)floor(yy)][(int)floor(xx + 0.000001)] == '1')
                    break;
            }
            else
            {
                if (cub->fov < 3 * M_PI / 2 && cub->fov > M_PI / 2)
                    xx -= b_1;
                else
                    xx += b_1;
                if (cub->fov < 2 * M_PI && cub->fov > M_PI)
                    yy -= dy;
                else
                    yy += dy;
                if (cub->map[(int)floor(yy - 0.000001)][(int)floor(xx)] == '1')
                    break;
                if (cub->map[(int)floor(yy + 0.000001)][(int)floor(xx)] == '1')
                    break;
            }
        // printf("xx - %f yy - %f fov - %f\n", xx, yy, cub->fov);
        }
		cub->dist_wall = sqrt(pow(xx - cub->x, 2) + pow(yy - cub->y, 2));
		drow_wall(cub, cub->fov, i);
		// printf("{ %f }", cub->fov);
		cub->fov += M_PI / 3 / cub->width;
	}
	
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image, 0, 0);
	return (0);
}

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

// 	while (i < 1199)
// 	 {

// 		 yy = cub->y;
// 		 yy1 = cub->y;
// 		 xx = cub->x;
// 		 xx1 = cub->x;
// 		while (1)
// 		{	
// 			if (dir >= 0 && dir < M_PI)
// 			{
// 				if (yy == cub->y)
// 				{
// 					yy = ceil(yy + 0.000001);
// 					xx =cub->x + fabs(cub->y - yy) / tan((2 * M_PI - dir));				
// 				}
// 				else
// 				{
// 					yy += 1;
// 					xx += 1 / tan((2 * M_PI - dir));
// 				}
// 			}
// 			else
// 			{
// 				if (yy == cub->y)
// 				{
// 					yy = floor(yy - 0.000001);
// 					xx = cub->x + fabs(cub->y - yy) / tan(2 * M_PI - dir);
// 				}
// 				else
// 				{
// 					yy -= 1;
// 					xx += 1 / tan(2 * M_PI - dir);
// 				}
// 			}
// 			if (dir >= M_PI / 2 && dir < 3 * M_PI / 2)
// 				if (xx1 == cub->x)
// 				{
// 					xx1 = floor(xx1 - 0.000001);
// 					yy1 =cub->y + fabs(cub->x - xx1) * tan(2 * M_PI - dir);
// 				}
// 				else
// 				{
// 					xx1 -= 1;
// 					yy1 += tan(2 * M_PI - dir);
// 				}
// 			else
// 				if (xx1 == cub->x)
// 				{
// 					xx1 = ceil(xx1 + 0.000001);
// 					yy1 =cub->y + fabs(cub->x - xx1) * tan(2 * M_PI - dir);
// 				}
// 				else
// 				{
// 					xx1 += 1;
// 					yy1 += tan(2 * M_PI - dir);
// 				}
// 			if (xx < 0 || yy < 0 || yy > 5 || xx > 5 || cub->map[(int)floor(yy - 0.000001)][(int)floor(xx)] == '1' || cub->map[(int)floor(yy + 0.000001)][(int)floor(xx)] == '1')
// 				dist_wall_x = sqrt(pow(xx - cub->x, 2) + pow(yy - cub->y, 2));
// 			if (xx1 < 0 || yy1 < 0 || yy1 > 5 || xx1 > 5 ||cub->map[(int)floor(yy1)][(int)floor(xx1 - 0.000001)] == '1' || cub->map[(int)floor(yy1)][(int)floor(xx1 + 0.000001)] == '1')
// 				dist_wall_y = sqrt(pow(xx1 - cub->x, 2) + pow(yy1 - cub->y, 2));
// 			if (dist_wall_x < dist_wall_y)
// 			{
// 				dist_wall = dist_wall_x;
// 				break ;
// 			}
// 			if (dist_wall_x > dist_wall_y)
// 			{
// 				dist_wall = dist_wall_y;
// 				break ;
// 			}
// 	}
// 		i++;
// 		drow_wall(dist_wall, cub, dir, i);
// 		dir -= M_PI / 6 / cub->width;
	
// 	}
// 		mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image, 0, 0);
// 	return (0);
// }