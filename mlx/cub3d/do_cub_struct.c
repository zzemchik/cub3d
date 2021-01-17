/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cub_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:57:17 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/17 16:18:46 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void all_null(t_cub *cub)
{
	cub->par->n_tex = NULL;
	cub->par->s_tex = NULL;
	cub->par->w_tex = NULL;
	cub->par->e_tex = NULL;
	cub->par->color_floor = NULL;
	cub->par->color_ceil = NULL;
	cub->par->size_screan = NULL;
	cub->lst = NULL;
	cub->height = 0;
	cub->width = 0;
	cub->size_line = 0;
	cub->b_ceil = 0;
	cub->g_ceil = 0;
	cub->r_ceil = 0;
	cub->b_floor = 0;
	cub->r_floor = 0;
	cub->g_floor = 0;
}

void all_free(t_cub *cub)
{
	int i;

	i = 0;
	free(cub->par->color_floor);
	free(cub->par->color_ceil);
	free(cub->par->n_tex);
	free(cub->par->s_tex);
	free(cub->par->w_tex);
	free(cub->par->e_tex);
	free(cub->par->size_screan); 
	free(cub->par);
	while (cub->map[i] != 0)
	{
		free(cub->map[i]);
		i++;
	}
	free(cub->map);
	free(cub);
}