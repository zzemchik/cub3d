/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:51:00 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/08 17:37:57 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	void help_texture(t_cub *cub, t_texture *a)
{
	int i;
	a->texture = mlx_xpm_file_to_image(cub->mlx, a->name_texture, \
	&(a->width), &(a->height));
	if (a->texture == 0)
	{	
		g_error = 2;
		return ;
	}
	a->add_texture = mlx_get_data_addr(a->texture, \
	&cub->bpp, &(a->size_line), &i);
	i = 0;

}
int			all_texure(t_cub *cub)
{
	help_texture(cub, &(cub->no));
	help_texture(cub, &(cub->so));
	help_texture(cub, &(cub->we));
	help_texture(cub, &(cub->ea));
	help_texture(cub, &(cub->sp));
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

int exita(t_cub *cub)
{
	all_free(cub);
    exit(0);
}

int main (int argv, char **argc) 
{
	t_cub	*cub;
	int		i;
	int		j;
	char	*a;
	if (argv > 3 || argv == 1)
	{
		write(1, "Error arguments!\n", 17);
		return (0);
	}
	i = ft_strlen(argc[1]);
	if (!(argc[1][i - 4] == '.' && argc[1][i - 3] == 'm' && \
	argc[1][i - 2] == 'a' && argc[1][i - 1] == 'p' && argc[1][i] == 0))
	{	
		write(1, "Error arguments!\n", 17);
		return (0);
	}
	if (argv == 3)
		if (!(argc[2][0] == '-' && argc[2][1] == '-' && argc[2][2] == 's' && argc[2][3] == 'a' && \
		argc[2][4] == 'v' && argc[2][5] == 'e' && argc[2][6] == 0))
	{	
		write(1, "Error arguments!\n", 17);
		return (0);
	}
	cub = malloc(sizeof(t_cub));
	g_error = 0;
	cub->map_file = argc[1];
	all_set(cub);
	i = 0;
 	if (g_error != 0)
	{
		all_free(cub);
		if (g_error == 2)
			write(1, "Error name texture!\n", 20);
		else
			write(1, "Error\n", 6);
		exit(0);
	}
	
	all_texure(cub);
	if (g_error != 0)
	{
		all_free(cub);
		if (g_error == 2)
			write(1, "Error name texture!\n", 20);
		else if (g_error == 1)
			write(1, "Error\n", 6);
		exit(0);
	}
	while (cub->map[i] != 0)
	{
		j = 0;
		while(cub->map[i][j])
		{
			if (cub->map[i][j] == 'N' || cub->map[i][j] == 'E' || \
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
	if (argv == 3)
	{
		scr_sh(cub);
		exita(cub);
	}
 	mlx_hook(cub->mlx_win, 2, 1L << 0, key_press, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 1, key_release, cub);
    mlx_hook(cub->mlx_win, 17, 1L << 17, exita, cub);
	mlx_loop_hook(cub->mlx, search_wall, cub);
    mlx_loop(cub->mlx);
	return (0);
}
