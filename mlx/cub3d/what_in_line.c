/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   what_in_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:47:17 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/16 17:02:58 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	skip_spaces(const char *line, int *i)
{
	while (line[*i] == ' ')
		(*i)++;
	(*i)++;
}

static void	valid_line_map(const char *line)
{
	int i;

	i = 0;
	while (line[i] != 0)
	{
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

static void	norm_what_in_line(char **str, char *line, int i)
{
	if (*str != 0)
		g_error = 1;
	skip_spaces(&line[i], &i);
	*str = ft_strdup(&line[i]);
}

static void	norm_what_in_line_2(t_cub *cub, char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		norm_what_in_line(&cub->par->n_tex, line, 2);
	else if (line[0] == 'S' && line[1] == 'O')
		norm_what_in_line(&cub->par->s_tex, line, 2);
	else if (line[0] == 'W' && line[1] == 'E')
		norm_what_in_line(&cub->par->w_tex, line, 2);
	else if (line[0] == 'E' && line[1] == 'A')
		norm_what_in_line(&cub->par->e_tex, line, 2);
	else if (line[0] == 'F')
		norm_what_in_line(&cub->par->color_floor, line, 2);
	else if (line[0] == 'C')
		norm_what_in_line(&cub->par->color_ceil, line, 2);
	else if (line[0] == 'R')
		norm_what_in_line(&cub->par->size_screan, line, 2);
}

void		what_in_line(char *line, t_cub *cub)
{
	if (g_error == 0)
	{
		if (line == 0 || line[0] == 0)
			return ;
		if (cub->par->n_tex != 0 && cub->par->s_tex &&
		cub->par->w_tex != 0 && cub->par->size_screan != 0 &&
		cub->par->e_tex != 0 && cub->par->color_floor != 0 &&
		cub->par->color_ceil != 0)
		{
			valid_line_map(line);
			ft_lstadd_back(&cub->lst, ft_lstnew(ft_strdup(line)));
		}
		else
			norm_what_in_line_2(cub, line);
	}
}
