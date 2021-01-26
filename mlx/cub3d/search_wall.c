/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_wall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 17:02:40 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/25 18:48:35 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	search_wall_norm(t_cub *cub, int *i)
{

}

int			search_wall(t_cub *cub)
{
    
	int		i;
    int	    u;
	double	xx;
	double	yy;
	double	dx;
	double	dy;
	double	b_1;
	double	a_1;
	double	a_gip;
	double	b_gip;
    u = 0;



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
                    break;
                }
                if (cub->map[(int)floor(yy)][(int)floor(xx + 0.000001)] == '1')
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
                    break;
                }
                if (cub->map[(int)floor(yy)][(int)floor(xx - 0.000001)] == '2')
                { 
                    if (u == 0)
                    {
                        cub->sprite_x[u] =  (int)floor(xx - 0.000001);
                        cub->sprite_y[u] = (int)floor(yy);
                        u++;
                    }
                    else if (!(cub->sprite_x[u - 1] == (int)floor(xx - 0.000001) && cub->sprite_y[u - 1] == (int)floor(yy)))
                    {   
                        cub->sprite_x[u] =  (int)floor(xx - 0.000001);
                        cub->sprite_y[u] = (int)floor(yy);
                        u++;
                    }
                }
                else if (cub->map[(int)floor(yy)][(int)floor(xx + 0.000001)] == '2')
                {
                    if (u == 0)
                    {
                        cub->sprite_x[u] = (int)floor(xx + 0.000001);
                        cub->sprite_y[u] = (int)floor(yy);
                        u++;
                    }
                    else if (!(cub->sprite_x[u - 1] == (int)floor(xx + 0.000001) && cub->sprite_y[u - 1] == (int)floor(yy)))
                    {   
                        cub->sprite_x[u] = (int)floor(xx + 0.000001);
                        cub->sprite_y[u] = (int)floor(yy);
                        u++;
                    }
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
                    break;
                }
                if (cub->map[(int)floor(yy + 0.000001)][(int)floor(xx)] == '1')
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
                    break;
                }
                if (cub->map[(int)floor(yy - 0.000001)][(int)floor(xx)] == '2')
                {  
                    if (u == 0)
                    {
                        cub->sprite_x[u] =  (int)floor(xx);
                        cub->sprite_y[u] = (int)floor(yy - 0.000001);
                        u++;
                    }
                    else if (!(cub->sprite_x[u - 1] == (int)floor(xx) && cub->sprite_y[u - 1] == (int)floor(yy  - 0.000001)))
                    {   
                        cub->sprite_x[u] =  (int)floor(xx);
                        cub->sprite_y[u] = (int)floor(yy - 0.000001);
                        u++;
                    }
                }
                else if (cub->map[(int)floor(yy + 0.000001)][(int)floor(xx)] == '2')
                {   
                    if (u == 0)
                    {
                        cub->sprite_x[u] =  (int)floor(xx);
                        cub->sprite_y[u] = (int)floor(yy + 0.000001);
                        u++;
                    }
                    else if (!(cub->sprite_x[u - 1] == (int)floor(xx) && cub->sprite_y[u - 1] == (int)floor(yy  + 0.000001)))
                    {   
                        cub->sprite_x[u] =  (int)floor(xx);
                        cub->sprite_y[u] = (int)floor(yy + 0.000001);
                        u++;
                    }
                }
            }
        }
		cub->dist_wall = sqrt(pow(xx - cub->x, 2) + pow(yy - cub->y, 2));
		drow_wall(cub, i);
        // printf("%d\n", u);
        if (u != 0)
            drow_sprite(cub, u, i);
        while (u > 0)
        {
            u--;
            // printf("{%d %d}\n", cub->sprite_x[u], cub->sprite_y[u]);
            cub->sprite_x[u] = 0;
            cub->sprite_y[u] = 0;
           
        }
		cub->fov += M_PI / 3 / cub->width;
	}
    //    clock_t end = clock();
    //    printf("%f\n", (double)(end - begin) / CLOCKS_PER_SEC);
	// where_sprite(cub, i);
    // if(cub->dist_sprite != 0)
    
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image, 0, 0);
  
	
	return (0);
}