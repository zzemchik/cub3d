/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 17:10:06 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/23 20:23:06 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		norm_valid_map_2(char **map, int i, int j)
{
	int k;
	int n;

	k = 0;
	n = j;
	while (n != -1)
	{
		if (map[i][n] == '0' && n != 0 && map[i][n - 1] == ' ')
			break ;
		else if ((n == 0 || map[i][n - 1] == ' ') &&
		map[i][n] == '1' && (k = k + 1))
			break ;
		n--;
	}
	n = j;
	while (map[i][n] != 0)
	{
		if (map[i][n] == '0' && map[i][n + 1] == ' ')
			break ;
		else if ((map[i][n + 1] == 0 || map[i][n + 1] == ' ') &&
		map[i][n] == '1' && (k = k + 1))
			break ;
		n++;
	}
	return (k);
}

int		norm_valid_map_1(char **map, int i, int j)
{
	int k;
	int n;

	k = 0;
	n = i;
	while (n != -1)
	{
		if (map[n][j] == '0' && n != 0 && map[n - 1][j] == ' ')
			break ;
		else if ((n == 0 || map[n - 1][j] == ' ') &&
		map[n][j] == '1' && (k = k + 1))
			break ;
		n--;
	}
	n = i;
	while (map[n] != NULL)
	{
		if (map[n][j] == '0' && map[n + 1] != 0 && map[n + 1][j] == ' ')
			break ;
		else if ((map[n + 1] == 0 || map[n + 1][j] == ' ') &&
		map[n][j] == '1' && (k = k + 1))
			break ;
		n++;
	}
	return (k);
}

int		norm_valid_map(char **map, int i, int j, t_cub *cub)
{
	int k;
	int m;
	int g;

	k = 0;
	g = 0;
	m = 0;
	if (map[i][j] == 'N' || map[i][j] == 'S' ||
	map[i][j] == 'W' || map[i][j] == 'E')
	{
		
		if (m == 0)
			m = 1;
		else
		{
			g_error = 1;
		}
	}
	if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' ||
	map[i][j] == 'E' || map[i][j] == '2' || map[i][j] == '0')
	{
		if (map[i][j] == '2')
		{
			cub->sprite_x[g] = j;
			cub->sprite_y[g] = i;
			g++;
		}
		k += norm_valid_map_1(map, i, j);
		k += norm_valid_map_2(map, i, j);
		if (k != 4)
			g_error = 1;
	}
	return (m);
}

void	valid_map(char **map, t_cub *cub)
{
	int i;
	int j;
	int k;
	int n;
	int m;

	i = 0;
	m = 0;
	while (map[i] != NULL)
	{
		j = 0;
		if (g_error != 0)
			break ;
		while (map[i][j] != 0)
		{
			if (g_error != 0)
				break ;
			m += norm_valid_map(map, i, j, cub);
			j++;
		}
		i++;
	}
	if (m == 0)
		g_error = 1;
}
