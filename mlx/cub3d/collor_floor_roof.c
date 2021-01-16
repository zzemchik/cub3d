/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collor_floor_roof.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:50:52 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/14 16:51:33 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int color_floor_roof(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (i < cub->width && (j = 0) == 0 && ++i)
		while (j < cub->height / 2)
		{	
			my_mlx_pixel_put(i, j, 0x56C5FF, cub->data, cub->size_line);
			j++;
		}
	i = 0;
	while (i < cub->width && (j = cub->height / 2) == cub->height / 2 && ++i)
		while (j < cub->height)
		{	
			my_mlx_pixel_put(i, j, 0x252525, cub->data, cub->size_line);
			j++;
		}
	return (0);
}