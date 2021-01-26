/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drow_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:03:05 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/26 19:14:45 by rnancee          ###   ########.fr       */
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
// void	drow_wall_sprite(t_cub *cub, int i)
// {
// 	int			j;
// 	int f;
// 	double		h_wall;
// 	unsigned int color;
// 	char 		*xpm_data;
// 	double	kall;
// 	double max;
// 	double hit;

// 	hit = cub->hit * cub->width_texture;
// 	j = 0;
// 	kall = 0;
// 	cub->dist_sprite_q = cub->dist_sprite_q * cos(cub->fov - cub->direction);
// 	h_wall = cub->height / 4;
// 	j = (cub->height - h_wall) / 2;
// 	max = (cub->height + h_wall) / 2;
//  	if (j < 0)
//     {
//         kall = (double)cub->height_texture / (double)h_wall * (-j);
//         j = 0;
//         max = cub->height;
//     }
// 	while (j < max)
// 	{
// 		my_mlx_pixel_put(i, j, 0x000000, cub);
// 		j++;
// 		kall += (double)cub->height_texture / (double)h_wall;
// 	}

// }

void	sort_dist_sprite(t_cub *cub, int k)
{
	int i;
	int j;
	double h;
	int l;
	j = 0;
	i = 0;
	while (i < k)
	{
		h = cub->dist_sprite[i];
		j = i + 1;
		while (j < k)
		{
			if (h > cub->dist_sprite[j])
			{
				h = cub->dist_sprite[j];
				l = j;
			}
		j++;
		}
		if (h != cub->dist_sprite[i])
		{
			cub->dist_sprite[l] = cub->dist_sprite[i];
			cub->dist_sprite[i] = h;
            h = cub->sprite_x[i];
            cub->sprite_x[i] = cub->sprite_x[l];
            cub->sprite_x[l] = h;
            h = cub->sprite_y[i];
            cub->sprite_y[i] = cub->sprite_y[l];
            cub->sprite_y[l] = h;
		}
		i++;
	}
}

void			drow_sprite(t_cub *cub, int k, int i)
{
    int u;
    double w_sprite;
    double dir_sprite;
    int point_sprite;
    int size;
    u = 0;
    while (u < k)
    {
        cub->dist_sprite[u] = sqrt(pow(cub->x - 0.5 - cub->sprite_x[u], 2) + pow(cub->y - 0.5 - cub->sprite_y[u], 2));
        u++;
    }
    sort_dist_sprite(cub, k);
    u = 0;
    while (k--)
    {
        w_sprite = (double)(cub->width / 2) / tan(M_PI / 6);
        dir_sprite = atan2(cub->sprite_y[k] - cub->y + 0.5, cub->sprite_x[k] - cub->x + 0.5) - cub->direction;
        size = w_sprite / (cos(dir_sprite) * cub->dist_sprite[k]);
        point_sprite = cub->width / 2 + tan(dir_sprite) * w_sprite - size / 2;
        if (size <= 0 || point_sprite >= cub->width || i < point_sprite || i >= point_sprite + size)
            continue ;
        if (cub->dist_sprite[k] <= cub->dist_wall)
            d(cub, i, size, point_sprite);
        // printf("%f\n", cub->dist_sprite[k]);
    }
    
    //    clock_t end = clock();
    //    printf("%f\n", (double)(end - begin) / CLOCKS_PER_SEC);
	// where_sprite(cub, i);
    // if(cub->dist_sprite != 0)
    // drow_sprite(cub, u);
	// mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image, 0, 0);
}

// void        d_s(t_all *cub, t_sprite sprite, float x1, float y1)
// {
//     t_sprite ang;
//     t_sprite dist;
//     int     tx;
//     int     size;
//     ang.x = cub->plr.route + 0.25f;
//     if (ang.x > 1.0f)
//         ang.x -= 1.0f;
//     ang.x *= (2 * M_PI);
//     dist.y = (float)(cub->scene.screen_width / 2) / tan((60.0f * M_PI / 180.0f) / 2);
//     sprite.distance = sqrtf(powf(cub->plr.x0 - (sprite.x + 0.5f), 2) + powf(cub->plr.y0 - (sprite.y + 0.5f), 2));
//     ang.y = atan2(cub->plr.y0 - (sprite.y + 0.5f), cub->plr.x0 - (sprite.x + 0.5f)) - ang.x; // абсолютное направление от игрока до спрайта
//     size = dist.y / (cosf(ang.y) * sprite.distance);                                        // ширина и высота спрайта (квадратный)
//     tx = cub->scene.screen_width / 2 + tan(ang.y) * dist.y - size / 2;                      // точка пересечения луча со спрайтом
//     if (size <= 0 || tx < -size || tx >= cub->scene.screen_width \
//     || cub->x < tx || cub->x > tx + size)
//         return ;
//     if (sprite.distance <= sqrtf(powf(x1 - cub->plr.x0, 2) + powf(y1 - cub->plr.y0, 2)))
//         draw_sprite(cub, ((cub->x - tx) / (float)size), size);
// }