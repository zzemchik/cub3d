/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cub_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:57:17 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/09 16:51:42 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	all_null(t_cub *cub)
{
	cub->no.name_texture = NULL;
	cub->so.name_texture = NULL;
	cub->we.name_texture = NULL;
	cub->ea.name_texture = NULL;
	cub->sp.name_texture = NULL;
	cub->lst = NULL;
	cub->height = 0;
	cub->width = 0;
	cub->ceil.r = -1;
	cub->ceil.b = -1;
	cub->ceil.g = -1;
	cub->floor.r = -1;
	cub->floor.b = -1;
	cub->floor.g = -1;
	cub->sprite_num = 0;
	cub->dist_sprite = 0;
	cub->x = 0;
	cub->y = 0;
	cub->direction = 0;
	cub->keys.w = 0;
	cub->keys.a = 0;
	cub->keys.s = 0;
	cub->keys.d = 0;
	cub->keys.left = 0;
	cub->keys.right = 0;
}

void	all_set(t_cub *cub)
{
	int nun;

	nun = 0;
	all_null(cub);
	parser(cub);
	if (g_error == 0)
	{
		cub->color_ceil = cub->ceil.r << 16 | cub->ceil.g << 8 | cub->ceil.b;
		cub->color_floor = cub->floor.r << 16 | \
		cub->floor.g << 8 | cub->floor.b;
		cub->bpp = 32;
		cub->dist = malloc(sizeof(double) * cub->width);
		cub->mlx = mlx_init();
		cub->cos = cos(cub->direction) * 0.05;
		cub->sin = sin(cub->direction) * 0.05;
		cub->image = mlx_new_image(cub->mlx, cub->width, cub->height);
		cub->data = mlx_get_data_addr(cub->image, \
		&cub->bpp, &cub->size_line, &nun);
		cub->mlx_win = mlx_new_window(cub->mlx, \
		cub->width, cub->height, "Cub3D");
		cub->dist_wall_all = malloc(sizeof(double) * cub->width);
	}
}

void	all_free(t_cub *cub)
{
	int i;

	i = 0;
	if (g_error != 3)
	{
		free(cub->no.name_texture);
		free(cub->so.name_texture);
		free(cub->we.name_texture);
		free(cub->ea.name_texture);
		free(cub->sp.name_texture);
		free(cub->dist);
		free(cub->sprite_x);
		free(cub->sprite_y);
		free(cub->dist_sprite);
		free(cub->dist_wall_all);
		while (cub->map[i] != 0)
		{
			free(cub->map[i]);
			i++;
		}
		free(cub->map);
	}
	free(cub);
}
