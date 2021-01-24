/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:03:05 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/24 21:09:17 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void drow_sprite(t_cub *cub, int n)
// {
// 		int			j;
// 	double		h_sprite;
// 	unsigned int color;
// 	char 		*xpm_data;
// 	double	kall;
// 	double max;
// 	double hit;
// 	double dist_sp;
// 	int i;

// 	n--;
// 	while (n >= 0)
// 	{
// 		dist_sp = sqrt(pow(cub->sprite_x[n] - cub->x + 0.5, 2) + pow(cub->sprite_y[n] - cub->y + 0.5, 2));
// 		hit = cub->hit_sprite * cub->width_texture;
// 		j = 0;
// 		kall = 0;
// 		h_sprite = cub->height / 2;
// 		h_sprite = h_sprite / tan((60 / 2) * (M_PI / 180));
// 		h_sprite = ceil(h_sprite / dist_sp);
// 		j = (cub->height - h_sprite) / 2;
// 		max = (cub->height + h_sprite) / 2;
// 		i = cub->sprite_x[n] * cub->width / dist_sp;
// 		j = cub->sprite_x[n] * cub->height / dist_sp;
// 		printf("%d\n", i);
// 		while (i < 20 + cub->sprite_x[n] *  dist_sp / cub->width)
// 		{
// 			j = cub->sprite_x[n] * cub->height / dist_sp;
// 			while (j < 20 + cub->sprite_x[n] *  dist_sp / cub->height)
// 			{
// 				my_mlx_pixel_put(i, j, 0x000000, cub);
// 				j++;
// 			}
// 			i++;
// 		}
// 		n--;
// 	}
// }
void	drow_wall_sprite(t_cub *cub, int i)
{
	int			j;
	int f;
	double		h_wall;
	unsigned int color;
	char 		*xpm_data;
	double	kall;
	double max;
	double hit;

	hit = cub->hit * cub->width_texture;
	j = 0;
	kall = 0;
	cub->dist_sprite_q = cub->dist_sprite_q * cos(cub->fov - cub->direction);
	h_wall = cub->height / 4;
	j = (cub->height - h_wall) / 2;
	max = (cub->height + h_wall) / 2;
 	if (j < 0)
    {
        kall = (double)cub->height_texture / (double)h_wall * (-j);
        j = 0;
        max = cub->height;
    }
	while (j < max)
	{
		my_mlx_pixel_put(i, j, 0x000000, cub);
		j++;
		kall += (double)cub->height_texture / (double)h_wall;
	}

}

int			drow_sprite(t_cub *cub, int u)
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
    u = 0;

//    clock_t begin = clock();

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
                {
					u = 0;
					break ;
				}
                if (cub->map[(int)floor(yy)][(int)floor(xx - 0.000001)] == '2')
                {
                    if (cub->fov < 3 * M_PI / 2 && cub->fov >= M_PI / 2)
                    {
                        cub->what_texture = 0;
                        cub->hit = yy - floor(yy);
                    }
                    else
                    {
                        cub->what_texture = 1; 
                        cub->hit = ceil(yy) - yy;
                    }
					u = 1;
                    break;
                }
				if (cub->map[(int)floor(yy)][(int)floor(xx + 0.000001)] == '1')
                {
					u = 0;
					break ;
				}
                if (cub->map[(int)floor(yy)][(int)floor(xx + 0.000001)] == '2')
                {
                   if (cub->fov < 3 * M_PI / 2 && cub->fov >= M_PI / 2)
                   {
                        cub->what_texture = 2; 
                        cub->hit = yy - floor(yy);
                   }
                    else
                    {
                        cub->what_texture = 3; 
                        cub->hit = ceil(yy) - yy;
                    }
					u = 1;
                    break;
                }
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
                {
				  	u = 0;
					break ;
				}
                if (cub->map[(int)floor(yy - 0.000001)][(int)floor(xx)] == '2')
                {  
                    if (cub->fov < M_PI && cub->fov >= 0)
                    {
                        cub->what_texture = 0;
                        cub->hit = ceil(xx) - xx;
                    }
                    else
                    {
                        cub->what_texture = 1;
                        cub->hit = xx - floor(xx);
                    }
					u = 1;
                    break;
                }
				if (cub->map[(int)floor(yy + 0.000001)][(int)floor(xx)] == '1')
                {
					u = 0;
					break ;
				}
                if (cub->map[(int)floor(yy + 0.000001)][(int)floor(xx)] == '2')
                {   
                    if (cub->fov < M_PI && cub->fov >= 0)
                    {
                        cub->what_texture = 2;
                        cub->hit = ceil(xx) - xx;
                    }
                    else
                    {
                        cub->what_texture = 3;
                        cub->hit = xx - floor(xx);
                    }
					u = 1;
                    break;
				}
            }
        }
		cub->dist_sprite_q = sqrt(pow(xx - cub->x, 2) + pow(yy - cub->y, 2));
		if (u == 1)
			drow_wall_sprite(cub, i);
		cub->fov += M_PI / 3 / cub->width;
	}
    //    clock_t end = clock();
    //    printf("%f\n", (double)(end - begin) / CLOCKS_PER_SEC);
	// where_sprite(cub, i);
    // if(cub->dist_sprite != 0)
    // drow_sprite(cub, u);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image, 0, 0);
  
	
	return (0);
}