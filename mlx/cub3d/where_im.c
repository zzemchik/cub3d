/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   where_im.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:58:04 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/27 17:27:17 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	norm_where_im_1(int key, t_cub *cub)
{
	if (key == D)
		if (cub->map[(int)(cub->y + cub->cos)][(int)(cub->x - cub->sin)] != '1' \
		&& cub->map[(int)(cub->y + cub->cos)][(int)(cub->x - cub->sin)] != '2')
		{
			cub->x -= cub->sin;
			cub->y += cub->cos;
		}
	if (key == W)
		if (cub->map[(int)(cub->y + cub->sin)][(int)(cub->x + cub->cos)] != '1' \
		&& cub->map[(int)(cub->y + cub->sin)][(int)(cub->x + cub->cos)] != '2')
		{
			cub->x += cub->cos;
			cub->y += cub->sin;
		}

}

static void	norm_where_im_2(int key, t_cub *cub)
{
	if (key == A)
		if (cub->map[(int)(cub->y - cub->cos)][(int)(cub->x + cub->sin)] != '1' && \
		cub->map[(int)(cub->y - cub->cos)][(int)(cub->x + cub->sin)] != '2')
		{
			cub->x += cub->sin;
			cub->y -= cub->cos;
		}
	if (key == S)
		if (cub->map[(int)(cub->y - cub->sin)][(int)(cub->x - cub->cos)] != '1' && \
		cub->map[(int)(cub->y - cub->sin)][(int)(cub->x - cub->cos)] != '2')
		{
			cub->x -= cub->cos;
			cub->y -= cub->sin;
		}
}

int			where_im(int key, t_cub *cub)
{
		
	if (key == ESC)
		exit(0);
	norm_where_im_1(key, cub);
	norm_where_im_2(key, cub);
	if (key == LEFT)
		cub->direction -= 0.08;
	if (key == RIGHT)
		cub->direction += 0.08;
	cub->direction = valid_pi(cub->direction);
	cub->cos = cos(cub->direction) * 0.2;
	cub->sin = sin(cub->direction) * 0.2;
	return (0);
}
