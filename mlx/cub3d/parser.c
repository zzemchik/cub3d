/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 18:07:08 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/17 20:30:48 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	give_size_screan(t_cub *cub)
{
	int i;

	i = 0;
	cub->height = ft_atoi_cub(cub->par->size_screan, &i);
	cub->width = ft_atoi_cub(cub->par->size_screan, &i);
	i = 0;
	cub->r_floor = ft_atoi_cub(cub->par->color_floor, &i);
	i++;
	cub->g_floor = ft_atoi_cub(cub->par->color_floor, &i);
	i++;
	cub->b_floor = ft_atoi_cub(cub->par->color_floor, &i);
	i = 0;
	cub->r_ceil = ft_atoi_cub(cub->par->color_ceil, &i);
	i++;
	cub->g_ceil = ft_atoi_cub(cub->par->color_ceil, &i);
	i++;
	cub->b_ceil = ft_atoi_cub(cub->par->color_ceil, &i);
}

void	valid_size_screan(char *str)
{
	int i;

	i = 0;
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
}

void	valid_ceil_floor(char *str)
{
	int i;
	int k;

	k = 0;
	i = 0;
	while (str[i] != 0)
	{
		if ((str[i] <= '9' && str[i] >= '0') || str[i] == ' ' || str[i] == ',')
		{
			i++;
			if (str[i] == ',')
				k++;
			continue;
		}
		g_error = 1;
		break ;
	}
	if (k != 2)
		g_error = 1;
}

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

	fd = open("map.txt", O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) != 0)
	{
		what_in_line(line, cub);
		free(line);
	}
	what_in_line(line, cub);
	free(line);
	close(fd);
	if (g_error == 0)
	{
		norm_parser(cub, i);
		valid_size_screan(cub->par->size_screan);
		valid_ceil_floor(cub->par->color_ceil);
		valid_ceil_floor(cub->par->color_floor);
		give_size_screan(cub);
		valid_map(cub->map);
	}
}



int		main ()
{
	t_cub *cub;
	t_list *lst_cpy;
	int i;
	
	g_error = 0;
	cub = malloc(sizeof(t_cub));
	cub->par = malloc(sizeof(t_parser));
	all_null(cub);
	parser(cub);
	// printf("%s\n", cub->par->size_screan);
	// printf("%s\n", cub->par->n_tex);
	// printf("%s\n", cub->par->w_tex);
	// printf("%s\n", cub->par->e_tex);
	// printf("%s\n", cub->par->s_tex);
	// printf("%s\n", cub->par->color_floor);
	// printf("%s\n", cub->par->color_ceil);
	// i = 0;
	// while (cub->map[i] != 0)
	// {
	// 	printf("%s\n", cub->map[i]);
	// 	i++;
	// }

	printf("width - %d height - %d\n",cub->width, cub->height);
	printf("%s\n%s\n", cub->par->color_ceil, cub->par->color_floor);
	printf("%s\n", cub->par->n_tex);
	printf("r_floor - %d g_floor - %d b_floor - %d\nr_ceil -  %d g_ceil - %d b_ceil - %d\n",
	cub->r_floor, cub->g_floor, cub->b_floor, cub->r_ceil, cub->g_ceil, cub->b_ceil);
	if (g_error != 0)
	{
		all_free(cub);
		printf("Error");
		exit(0);
	}
	all_free(cub);
}
