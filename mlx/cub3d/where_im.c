/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_im.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:58:04 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/14 17:01:56 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	norm_where_im(int key, t_cub *cub)
{
	if (key == A)
		if (cub->map[(int)(cub->y + cub->cos)][(int)(cub->x - cub->sin)] != '1')
		{
			cub->x -= cub->sin;
			cub->y += cub->cos;
		}
	if (key == W)
		if (cub->map[(int)(cub->y + cub->sin)][(int)(cub->x + cub->cos)] != '1')
		{
			cub->x += cub->cos;
			cub->y += cub->sin;
		}
	if (key == D)
		if (cub->map[(int)(cub->y - cub->cos)][(int)(cub->x + cub->sin)] != '1')
		{
			cub->x += cub->sin;
			cub->y -= cub->cos;
		}
	if (key == S)
		if (cub->map[(int)(cub->y - cub->sin)][(int)(cub->x - cub->cos)] != '1')
		{
			cub->x -= cub->cos;
			cub->y -= cub->sin;
		}
}

int			where_im(int key, t_cub *cub)
{
	if (key == ESC)
		exit(0);
	norm_where_im(key, cub);
	if (key == LEFT)
		cub->direction += 0.05;
	if (key == RIGHT)
		cub->direction -= 0.05;
	cub->direction = valid_pi(cub->direction);
	cub->cos = cos(cub->direction) * 0.05;
	cub->sin = sin(cub->direction) * 0.05;
	return (0);
}
