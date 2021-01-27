/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_in_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:47:17 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/27 19:07:26 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	valid_line_map(t_cub *cub, const char *line)
{
	int i;

	i = 0;
	while (line[i] != 0)
	{
		if(line[i] == '2')
			cub->sprite_num++;
		if (line[i] == '1' || line[i] == 'N' ||
		line[i] == 'S' || line[i] == 'W' ||
		line[i] == 'E' || line[i] == '2' ||
		line[i] == ' ' || line[i] == '0')
			i++;
		else
		{
			g_error = 1;
			break ;
		}
	}
}

static void	valid_size_screan(char *str, t_cub *cub, int i)
{

	while (str[i] != 0)
	{
		if ((str[i] <= '9' && str[i] >= '0') || str[i] == ' ')
		{
			i++;
			continue;
		}
		g_error = 1;
		break ;
	}
	i = 1;
	cub->height = ft_atoi_cub(str, &i);
	cub->width = ft_atoi_cub(str, &i);
	
}

static char	*norm_what_in_line(char **str, char *line, int i)
{
	if (*str != 0)
		g_error = 1;
	i = skip_spaces(&line[i], i);
	if (line[i] == ' ')
		i++;
	*str = ft_strdup(&line[i]);
	return (*str);
}

void	valid_ceil_floor(char *str, t_color *a, int i)
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
	a->b =ft_atoi_cub(str, &i);
	if (a->r < 0 || a->r > 255 || a->g < 0 || a->g > 255 || a->b < 0 || a->b > 255)
		g_error = 1;
}

void	valid_texture(char *texture)
{
	int i;

	i = ft_strlen(texture);
	if (texture[0] != '.' || texture[1] != '/' || texture[i - 1] != 'm' ||
	texture[i - 2] != 'p' || texture[i - 3] != 'x' || texture[i - 4] != '.')
		g_error = 2;
	
}

static void	norm_what_in_line_2(t_cub *cub, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		valid_texture(norm_what_in_line(&(cub->no.name_texture), line, 1));
	else if (line[0] == 'S' && line[1] == 'O')
		valid_texture(norm_what_in_line(&(cub->so.name_texture), line, 1));
	else if (line[0] == 'W' && line[1] == 'E')
		valid_texture(norm_what_in_line(&(cub->we.name_texture), line, 1));
	else if (line[0] == 'E' && line[1] == 'A')
		valid_texture(norm_what_in_line(&(cub->ea.name_texture), line, 1));
	else if (line[0] == 'F')
		valid_ceil_floor(line, &(cub->floor), 0);
	else if (line[0] == 'C')
		valid_ceil_floor(line, &(cub->ceil), 0);
	else if (line[0] == 'R')
		valid_size_screan(line, cub, 1);
	else if (line[0] == 'S')
		valid_texture(norm_what_in_line(&(cub->sp.name_texture), line, 1));
}

void		what_in_line(char *line, t_cub *cub)
{
	if (g_error == 0)
	{
		if (line == 0 || line[0] == 0)
			return ;
		if (cub->no.name_texture != 0 && cub->so.name_texture && \
		cub->we.name_texture != 0 && cub->width && cub->height && \
		cub->ea.name_texture != 0 && cub->ceil.r != -1 && cub->ceil.b != -1 && \
		cub->ceil.g != -1 && cub->floor.r != -1 && cub->floor.g != -1 && \
		cub->floor.b != -1 && cub->sp.name_texture != 0)
		{
			valid_line_map(cub, line);
			ft_lstadd_back(&cub->lst, ft_lstnew(ft_strdup(line)));
		}
		else
			norm_what_in_line_2(cub, line);
	}
}
