/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:07:08 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/08 17:34:29 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	space_map(char **str, int max, int num)
{
	char *str_cpy;

	while (max > num)
	{
		str_cpy = *str;
		*str = ft_strjoin(*str, " ");
		if (str_cpy)
			free(str_cpy);
		max--;
	}
}

void	norm_parser(t_cub *cub, int i)
{
	int		size_len;
	int		size_len_max;
	t_list	*lst_cpy;

	size_len_max = 0;
	cub->map = (char **)malloc(sizeof(char *) * (ft_lstsize(cub->lst) + 1));
	while (cub->lst != 0)
	{
		cub->map[i] = ft_strdup(cub->lst->line);
		size_len = ft_strlen(cub->map[i]);
		if (size_len > size_len_max)
			size_len_max = size_len;
		i++;
		lst_cpy = cub->lst;
		cub->lst = cub->lst->next;
		free(lst_cpy->line);
		free(lst_cpy);
	}
	cub->map[i] = 0;
	i = 0;
	while (cub->map[i] != 0)
	{
		space_map(&cub->map[i], size_len_max, ft_strlen(cub->map[i]));
		i++;
	}
}


void	parser(t_cub *cub)
{
	char	*line;
	int		fd;
	int		i;

	if ((fd = open(cub->map_file, O_RDONLY)) == -1)
		g_error = 3;
	i = 0;
	while ((i = get_next_line(fd, &line)) != 0 && g_error == 0)
	{
		if (i == -1)
		{
			g_error = 1;
			break ;
		}
		what_in_line(line, cub);
		free(line);
	}
	if (g_error == 0)
	{
		what_in_line(line, cub);
		free(line);
		close(fd);
		norm_parser(cub, i);
		valid_map(cub);
	}
}
