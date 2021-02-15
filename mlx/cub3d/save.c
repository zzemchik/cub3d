/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:53:14 by rmass             #+#    #+#             */
/*   Updated: 2021/02/12 16:25:43 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	header(t_cub *cub, int fd)
{
	int		gg;

	write(fd, "BM", 2);
	gg = cub->width * cub->height * 4;
	write(fd, &gg, 4);
	gg = 0;
	write(fd, &gg, 2);
	write(fd, &gg, 2);
	gg = 54;
	write(fd, &gg, 4);
	gg = 40;
	write(fd, &gg, 4);
	gg = cub->width;
	write(fd, &gg, 4);
	gg = cub->height;
	write(fd, &gg, 4);
	gg = 1;
	write(fd, &gg, 2);
	gg = 32;
	write(fd, &gg, 2);
	gg = 0;
	write(fd, &gg, 24);
}

int			scr_sh(t_cub *cub)
{
	int		fd;
	int		i;

	if ((fd = open("screenshot.bmp", \
	O_RDWR | O_CREAT | O_TRUNC, 00600 | 00060 | 00006)) < 0)
	{
		g_error = 1;
		return (0);
	}
	search_wall(cub);
	header(cub, fd);
	i = cub->height;
	while (--i >= 0)
		write(fd, cub->data + i * cub->width * 4, 4 * cub->width);
	close(fd);
	exita(cub);
	return (0);
}
