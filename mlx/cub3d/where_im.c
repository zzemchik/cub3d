/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_im.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:58:04 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/25 17:01:38 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	norm_where_im(int key, t_cub *cub)
{
	if (key == D)
		if (cub->map[(int)(cub->y + cub->cos)][(int)(cub->x - cub->sin)] != '1' && cub->map[(int)(cub->y + cub->cos)][(int)(cub->x - cub->sin)] != '2')
		{
			cub->x -= cub->sin;
			cub->y += cub->cos;
		}
	if (key == W)
		if (cub->map[(int)(cub->y + cub->sin)][(int)(cub->x + cub->cos)] != '1' && cub->map[(int)(cub->y + cub->sin)][(int)(cub->x + cub->cos)] != '2')
		{
			cub->x += cub->cos;
			cub->y += cub->sin;
		}
	if (key == A)
		if (cub->map[(int)(cub->y - cub->cos)][(int)(cub->x + cub->sin)] != '1' && cub->map[(int)(cub->y - cub->cos)][(int)(cub->x + cub->sin)] != '2')
		{
			cub->x += cub->sin;
			cub->y -= cub->cos;
		}
	if (key == S)
		if (cub->map[(int)(cub->y - cub->sin)][(int)(cub->x - cub->cos)] != '1' && cub->map[(int)(cub->y - cub->sin)][(int)(cub->x - cub->cos)] != '2')
		{
			cub->x -= cub->cos;
			cub->y -= cub->sin;
		}
}


// void dir_sprite(t_cub *cub)
// {
// 	int i;
// 	i = -1;
// 	while (i++ < cub->sprite_num)
// 		if(cub->sprite_x[i] >= cub->x && cub->sprite_y[i] > cub->y)
// 			cub->sprite_dir[i] = (acos(cub->sprite_x[i] - cub->x) / cub->dist_sprite[i]);
// 		else if (cub->sprite_x[i] >= cub->x && cub->sprite_y[i] < cub->y)
// 			cub->sprite_dir[i] = acos((cub->sprite_x[i] - cub->x) / cub->dist_sprite[i]) + M_PI;
// 		else if (cub->sprite_x[i] < cub->x && cub->sprite_y[i] <= cub->y)
// 			cub->sprite_dir[i] = acos((cub->x - cub->sprite_x[i]) / cub->dist_sprite[i]) + 3 * M_PI / 2;
// 		else
// 			cub->sprite_dir[i] = acos((cub->x - cub->sprite_x[i]) / cub->dist_sprite[i]) + M_PI / 2;
// }

int			where_im(int key, t_cub *cub)
{
		
	if (key == ESC)
		exit(0);
	norm_where_im(key, cub);
	if (key == LEFT)
		cub->direction -= 0.08;
	if (key == RIGHT)
		cub->direction += 0.08;
	cub->direction = valid_pi(cub->direction);
	cub->cos = cos(cub->direction) * 0.2;
	cub->sin = sin(cub->direction) * 0.2;
	// int i;
	// i = 0;
	// while (i < cub->sprite_num)
	// {
	// 	cub->dist_sprite[i] = sqrt(pow(cub->x - cub->sprite_x[i], 2) + pow(cub->y - cub->sprite_y[i], 2));
	// 	i++;
	// }
	// dir_sprite(cub);
	// sort_dist_sprite(cub);
	// i =0;
	// while (i < cub->sprite_num)
	// {
	// 	printf("%f, %f\n", cub->sprite_dir[i], cub->dist_sprite[i]);
	// 	i++;
	// }
	return (0);
}
