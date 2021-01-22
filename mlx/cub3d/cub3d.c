/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:51:00 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/22 18:51:49 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			all_texure(t_cub *cub)
{
	int i;

	i = 0;
	cub->texture_north = mlx_xpm_file_to_image(cub->mlx, cub->par->n_tex,
	&cub->width_texture, &cub->height_texture);
	cub->texture_add_north = mlx_get_data_addr(cub->texture_north,
	&cub->bpp, &cub->size_line_tn, &i);
	cub->texture_south = mlx_xpm_file_to_image(cub->mlx, cub->par->s_tex,
	&cub->width_texture_s, &cub->height_texture_s);
	cub->texture_add_south = mlx_get_data_addr(cub->texture_south,
	&cub->bpp, &cub->size_line_ts, &i);
	cub->texture_west = mlx_xpm_file_to_image(cub->mlx, cub->par->w_tex,
	&cub->width_texture_w, &cub->height_texture_w);
	cub->texture_add_west = mlx_get_data_addr(cub->texture_west,
	&cub->bpp, &cub->size_line_tw, &i);
	cub->texture_east = mlx_xpm_file_to_image(cub->mlx, cub->par->e_tex,
	&cub->width_texture_e, &cub->height_texture_e);
	cub->texture_add_east = mlx_get_data_addr(cub->texture_east,
	&cub->bpp, &cub->size_line_te, &i);
	return (0);
	
}

void            my_mlx_pixel_put(int x, int y, unsigned int color, t_cub *cub)
{
    char    *dst;
	if (x < 0 || y < 0 || x >= cub->width || y >= cub->height)
		return ;
    dst = cub->data + y * cub->size_line + x * 4;
    *(unsigned int*)dst = color;
}

int exita()
{
    exit(0);
}

int main () 
{
	t_cub *cub;
	cub = malloc(sizeof(t_cub));
	cub->par = malloc(sizeof(t_parser));
	int i;
	int j;
	g_error = 0;
	
	all_set(cub);
	i = 0;
 	if (g_error != 0)
	{
		all_free(cub);
		printf("Error");
		exit(0);
	}
	
	all_texure(cub);
	while (cub->map[i] != 0)
	{
		j = 0;
		while(cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'E' ||
			cub->map[i][j] == 'S' || cub->map[i][j] == 'W')
			{
				cub->x = j + 0.5;
				cub->y = i + 0.5;

				if (cub->map[i][j] == 'N')
					cub->direction = 3 * M_PI / 2;
				else if (cub->map[i][j] == 'E')
						cub->direction = 0;
				else if (cub->map[i][j] == 'S')
					cub->direction = M_PI / 2;
				else if (cub->map[i][j] == 'W')
					cub->direction = M_PI;
			}
			j++;
		}
		i++;
	}
 	mlx_hook(cub->mlx_win, 2, 1L << 0, where_im, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 1, where_im, cub);
    mlx_hook(cub->mlx_win, 17, 1L << 17, exita, 0);
	mlx_loop_hook(cub->mlx, drowing_loop, cub);
    mlx_loop(cub->mlx);
    all_free(cub);
}
	//mini_map

	// while (cub->map[i])
	// {
	// 	j = 0;
	// 	while(cub->map[i][j])
	// 	{
	// 		if (cub->map[i][j] == '1')
	// 			{
	// 			x = 0;
	// 			while (x < 200)
	// 				{
	// 				y = 0;
	// 				while (y < 200)
	// 				{
	// 					my_mlx_pixel_put(i * 200 + x, j * 200 + y, 0x3431fe, cub->data, cub->size_line);
	// 					y++;
	// 				}
	// 				x++;
	// 				}
	// 			}
	// 		j++;
	// 	}
	// i++;
	// }
	// i = cub->x * 200;
	// while (i < cub->x * 200 + 15)
	// { 
	// 	j = cub->y * 200;
	// 	while (j < cub->y * 200 + 15)
	// 	{
	// 		my_mlx_pixel_put(i, j, 0x34F800, cub->data, cub->size_line);
	// 		my_mlx_pixel_put(cub->x * 200 - (i - cub->x * 200), j, 0x34F800, cub->data, cub->size_line);
	// 		my_mlx_pixel_put(i, cub->y * 200 - (j - cub->y * 200), 0x34F800, cub->data, cub->size_line);
	// 		my_mlx_pixel_put(cub->x * 200 - (i - cub->x * 200), cub->y * 200 - (j - cub->y * 200), 0x34F800, cub->data, cub->size_line);
	// 		j++;
	// }
	// 	i++;
	// }
