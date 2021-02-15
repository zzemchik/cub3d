/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:10:06 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/12 13:58:38 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int			norm_valid_map_2(t_cub *cub, int i, int j)
{
	int k;
	int n;

	k = 0;
	n = j;
	while (n != -1)
	{
		if (cub->map[i][n] == '0' && n != 0 && cub->map[i][n - 1] == ' ')
			break ;
		else if ((n == 0 || cub->map[i][n - 1] == ' ') &&
		cub->map[i][n] == '1' && (k = k + 1))
			break ;
		n--;
	}
	n = j;
	while (cub->map[i][n] != 0)
	{
		if (cub->map[i][n] == '0' && cub->map[i][n + 1] == ' ')
			break ;
		else if ((cub->map[i][n + 1] == 0 || cub->map[i][n + 1] == ' ') &&
		cub->map[i][n] == '1' && (k = k + 1))
			break ;
		n++;
	}
	return (k);
}

static int			norm_valid_map_1(t_cub *cub, int i, int j)
{
	int k;
	int n;

	k = 0;
	n = i;
	while (n != -1)
	{
		if (cub->map[n][j] == '0' && n != 0 && cub->map[n - 1][j] == ' ')
			break ;
		else if ((n == 0 || cub->map[n - 1][j] == ' ') &&
		cub->map[n][j] == '1' && (k = k + 1))
			break ;
		n--;
	}
	n = i - 1;
	while (cub->map[++n] != NULL)
	{
		if (cub->map[n][j] == '0' && cub->map[n + 1] != 0 && \
		cub->map[n + 1][j] == ' ')
			break ;
		else if ((cub->map[n + 1] == 0 || cub->map[n + 1][j] == ' ') && \
		cub->map[n][j] == '1' && (k = k + 1))
			break ;
	}
	return (k);
}

static int			norm_valid_map(int i, int j, t_cub *cub)
{
	int k;
	int m;

	k = 0;
	m = 0;
	if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' ||
	cub->map[i][j] == 'W' || cub->map[i][j] == 'E')
	{
		if (m == 0)
			m = 1;
		else
		{
			g_error = 1;
		}
	}
	if (cub->map[i][j] == 'N' || cub->map[i][j] == 'S' || cub->map[i][j] == 'W'
	|| cub->map[i][j] == 'E' || cub->map[i][j] == '2' || cub->map[i][j] == '0')
	{
		k += norm_valid_map_1(cub, i, j);
		k += norm_valid_map_2(cub, i, j);
		if (k != 4)
			g_error = 1;
	}
	return (m);
}

void				valid_map(t_cub *cub)
{
	int i;
	int j;
	int m;

	i = -1;
	m = 0;
	cub->dist_sprite = malloc(sizeof(double) * (cub->sprite_num + 1));
	cub->dist_sprite[cub->sprite_num] = 0;
	cub->sprite_x = malloc(sizeof(int) * cub->sprite_num + 1);
	cub->sprite_x[cub->sprite_num] = 0;
	cub->sprite_y = malloc(sizeof(int) * cub->sprite_num + 1);
	cub->sprite_y[cub->sprite_num] = 0;
	while (cub->map[++i] != NULL)
	{
		j = -1;
		while (cub->map[i][++j] != 0)
			m += norm_valid_map(i, j, cub);
	}
	if (m != 1)
		g_error = 1;
}
