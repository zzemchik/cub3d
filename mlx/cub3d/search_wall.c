#include "cub3d.h"

static void	search_wall_norm(t_cub *cub, t_ray *ray)
{
	if (cub->fov < 2 * M_PI && cub->fov > M_PI)
		ray->dy = ray->yy - floor(ray->yy - EPS);
	else
		ray->dy = ceil(ray->yy + EPS) - ray->yy;
	if (cub->fov < 3 * M_PI / 2 && cub->fov > M_PI / 2)
		ray->dx = ray->xx - floor(ray->xx - EPS);
	else
		ray->dx = ceil(ray->xx + EPS) - ray->xx;
	if ((cub->fov > 0 && cub->fov < M_PI / 2) || \
	(cub->fov > M_PI && cub->fov < 3 * M_PI / 2))
	{
		ray->a_1 = tan(fmod(cub->fov, M_PI / 2)) * ray->dx;
		ray->b_1 = tan(M_PI / 2 - fmod(cub->fov, M_PI / 2)) * ray->dy;
	}
	else
	{
		ray->b_1 = tan(fmod(cub->fov, M_PI / 2)) * ray->dy;
		ray->a_1 = tan(M_PI / 2 - fmod(cub->fov, M_PI / 2)) * ray->dx;
	}
	ray->b_gip = sqrt(pow(ray->b_1, 2) + pow(ray->dy, 2));
	ray->a_gip = sqrt(pow(ray->a_1, 2) + pow(ray->dx, 2));
}

static void	search_wall_norm_2(t_cub *cub, t_ray *ray, int *u)
{
	while (1)
	{
		search_wall_norm(cub, ray);
		if (ray->b_gip > ray->a_gip)
		{
			if (dist_a(cub, ray, u) == 1)
				break ;
		}
		else
		{
			if (dist_b(cub, ray, u) == 1)
				break ;
		}
	}
}

int			search_wall(t_cub *cub)
{
	int		i;
	int		u;
	t_ray	ray;

	u = 0;
	movement(cub);
	cub->fov = cub->direction - M_PI / 6;
	i = -1;
	while (++i < cub->width)
	{
		cub->fov = valid_pi(cub->fov);
		ray.xx = cub->x;
		ray.yy = cub->y;
		search_wall_norm_2(cub, &ray, &u);
		cub->dist_wall = sqrt(pow(ray.xx - cub->x, 2) + \
		pow(ray.yy - cub->y, 2));
		cub->dist_wall_all[i] = cub->dist_wall;
		drow_wall(cub, i);
		cub->fov += M_PI / 3 / cub->width;
	}
	drow_sprite(cub, u);
	mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image, 0, 0);
	return (0);
}
