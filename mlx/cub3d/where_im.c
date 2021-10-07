#include "cub3d.h"

void		movement_norm_1(t_cub *cub)
{
	double s;
	double c;

	c = cub->cos * 2;
	s = cub->sin * 2;
	if (cub->keys.a)
	{
		if (cub->map[(int)(cub->y - c)][(int)(cub->x + s)] != '1')
		{
			cub->x += cub->sin;
			cub->y -= cub->cos;
		}
	}
	if (cub->keys.s)
	{
		if (cub->map[(int)(cub->y - s)][(int)(cub->x - c)] != '1')
		{
			cub->x -= cub->cos;
			cub->y -= cub->sin;
		}
	}
}

void		movement_norm_2(t_cub *cub)
{
	if (cub->keys.left)
		cub->direction -= 0.07;
	if (cub->keys.right)
		cub->direction += 0.07;
}

void		movement(t_cub *cub)
{
	double s;
	double c;

	c = cub->cos * 2;
	s = cub->sin * 2;
	if (cub->keys.d)
	{
		if (cub->map[(int)(cub->y + c)][(int)(cub->x - s)] != '1')
		{
			cub->x -= cub->sin;
			cub->y += cub->cos;
		}
	}
	if (cub->keys.w)
	{
		if (cub->map[(int)(cub->y + s)][(int)(cub->x + c)] != '1')
		{
			cub->x += cub->cos;
			cub->y += cub->sin;
		}
	}
	movement_norm_1(cub);
	movement_norm_2(cub);
	cub->cos = cos(cub->direction) * 0.1;
	cub->sin = sin(cub->direction) * 0.1;
}

int			key_release(int key, t_cub *cub)
{
	if (key == A)
		cub->keys.a = 0;
	if (key == S)
		cub->keys.s = 0;
	if (key == D)
		cub->keys.d = 0;
	if (key == W)
		cub->keys.w = 0;
	if (key == LEFT)
		cub->keys.left = 0;
	if (key == RIGHT)
		cub->keys.right = 0;
	return (0);
}

int			key_press(int key, t_cub *cub)
{
	if (key == ESC)
	{
		all_free(cub);
		exit(0);
	}
	if (key == A)
		cub->keys.a = 1;
	if (key == S)
		cub->keys.s = 1;
	if (key == D)
		cub->keys.d = 1;
	if (key == W)
		cub->keys.w = 1;
	if (key == LEFT)
		cub->keys.left = 1;
	if (key == RIGHT)
		cub->keys.right = 1;
	return (0);
}
