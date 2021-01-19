/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_all.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:54:58 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/18 13:14:27 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	set_all(t_cub *cub)
{
	int nun;

	nun = 0;
	cub->x = 0;
	cub->y = 0;
	cub->width = 1200;
	cub->bpp = 32;
	cub->height = 1200;
	cub->dist = malloc(sizeof(double) * cub->width);
	cub->mlx = mlx_init();
	cub->direction = 0;
	cub->cos = cos(cub->direction) * 0.05;
	cub->sin = sin(cub->direction) * 0.05;
	cub->mlx_win = mlx_new_window(cub->mlx, cub->width, cub->height, "Cub3D");
	cub->image = mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->data = mlx_get_data_addr(cub->image, &cub->bpp, &cub->size_line, &nun);
}