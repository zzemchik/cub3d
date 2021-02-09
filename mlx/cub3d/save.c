/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:53:14 by rmass             #+#    #+#             */
/*   Updated: 2021/02/09 16:30:57 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	bmp_header(t_cub *cub, int fd)
{
	int		t;
	short	d;

	write(fd, "BM", 2);
	t = 14 + 40 + cub->width * cub->height * 4;
	write(fd, &t, sizeof(t));
	d = 0;
	write(fd, &d, sizeof(d));
	write(fd, &d, sizeof(d));
	t = 14 + 40;
	write(fd, &t, sizeof(t));
}

void	image_header(t_cub *cub, int fd)
{
	int		t;
	short	d;

	t = 40;
	write(fd, &t, sizeof(t));
	t = cub->width;
	write(fd, &t, sizeof(t));
	t = cub->height;
	write(fd, &t, sizeof(t));
	d = 1;
	write(fd, &d, sizeof(d));
	d = 32;
	write(fd, &d, sizeof(d));
	t = 0;
	write(fd, &t, sizeof(t));
	t = cub->width * cub->height * 4;
	write(fd, &t, sizeof(t));
	t = 2795;
	write(fd, &t, sizeof(t));
	write(fd, &t, sizeof(t));
	t = 0;
	write(fd, &t, sizeof(t));
	write(fd, &t, sizeof(t));
}

int		scr_sh(t_cub *cub)
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
	bmp_header(cub, fd);
	image_header(cub, fd);
	i = cub->height;
	while (--i >= 0)
		write(fd, cub->data + i * cub->width * 4, 4 * cub->width);
	close(fd);
	exita(cub);
	return (0);
}
