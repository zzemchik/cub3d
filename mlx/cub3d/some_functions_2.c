/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:32:55 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/10 14:05:13 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_atoi_cub(const char *str, int *i)
{
	int k;
	int num;

	k = 1;
	num = 0;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-' && ((*i)++))
		k = -1;
	while (str[*i] <= '9' && str[*i] >= '0')
	{
		num = 10 * num + (str[*i] - '0');
		(*i)++;
		if (num > 10000)
			break ;
	}
	while (str[*i] <= '9' && str[*i] >= '0')
		(*i)++;
	return (num * k);
}

int		skip_spaces(const char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return (i);
}

void	my_mlx_pixel_put(int x, int y, unsigned int color, t_cub *cub)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= cub->width || y >= cub->height)
		return ;
	dst = cub->data + y * cub->size_line + x * 4;
	*(unsigned int*)dst = color;
}

int		exita(t_cub *cub)
{
	all_free(cub);
	exit(0);
}

void	error_1(t_cub *cub)
{
	if (g_error != 0)
	{
		all_free(cub);
		if (g_error == 2)
			write(1, "Error name texture!\n", 20);
		else
			write(1, "Error\n", 6);
		exit(0);
	}
}
