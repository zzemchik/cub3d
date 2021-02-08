/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_in_line_norm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 16:04:16 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/29 16:05:35 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		valid_texture(char *texture)
{
	int i;

	i = ft_strlen(texture);
	if (texture[0] != '.' || texture[1] != '/' || texture[i - 1] != 'm' ||
	texture[i - 2] != 'p' || texture[i - 3] != 'x' || texture[i - 4] != '.')
		g_error = 2;
}

void		valid_ceil_floor(char *str, t_color *a, int i)
{
	int k;

	k = 0;
	while (str[++i] != 0)
	{
		if ((str[i] <= '9' && str[i] >= '0') || str[i] == ' ' || str[i] == ',')
		{
			if (str[i] == ',')
				k++;
			continue;
		}
		g_error = 1;
		break ;
	}
	if (k != 2)
		g_error = 1;
	i = 1;
	a->r = ft_atoi_cub(str, &i);
	i++;
	a->g = ft_atoi_cub(str, &i);
	i++;
	a->b = ft_atoi_cub(str, &i);
	if (a->r < 0 || a->r > 255 || a->g < 0 || \
	a->g > 255 || a->b < 0 || a->b > 255)
		g_error = 1;
}
