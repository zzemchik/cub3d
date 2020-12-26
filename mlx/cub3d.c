#include "cub3d.h"
#include "mlx.h"


int g_i;
int g_j;
int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != 0)
		i++;
	return (i);
}

typedef struct	s_cub
{
    double	*dist;
    void	*mlx;
    void	*mlx_win;
	int		width;
	int		height;
	void	*image;
	char	**map;
	char	*data;
	int		size_line;
	int		bpp;
	double	wall;
	double cos;
	double sin;
	double	x;
	double	y;
	double	direction;
}				t_cub;

double		map_wall(double x, double y, t_cub *cub)
{
	double distance;
	int i;
	int j;

	distance = -1;
	if (x != floor(x))
		i = floor(x);
	else
		i = floor(x - 0.1);
	if (y != floor(y))
		j = floor(y);
	else
		j = floor(y - 0.1);
	if (j > 5)
		j = 5;
	if (i > 5)
		i = 5;
	if (i < 0)
		i = 0;
	if (j < 0)
		j = 0;
	if (cub->map[i][j] == '1')
	{
		distance = sqrt(pow(x - cub->x, 2) + pow(y - cub->y, 2));
		return (distance);
	}
	return (distance);
}

double valid_pi(double dir)
{
	while (dir > 2 * M_PI)
		dir -= 2 * M_PI;
	while (dir < 0)
		dir += 2 * M_PI;
	return (dir);
}

void set_all(t_cub *cub)
{
	int nun = 0;
	cub->x = 0;
	cub->y = 0;
	cub->width = 1200;
	cub->bpp = 32;
	cub->height = 1200;
	cub->dist = malloc(sizeof(double) * cub->width);
	cub->mlx = mlx_init();
	cub->direction = 0;
	cub->cos = cos(cub->direction) * 0.05;
	cub->sin = sin(cub->direction) * 0.05;
    cub->mlx_win = mlx_new_window(cub->mlx, cub->width, cub->height, "Cub3D");
    cub->image =  mlx_new_image(cub->mlx, cub->width, cub->height);
	cub->data = mlx_get_data_addr(cub->image, &cub->bpp, &cub->size_line, &nun);
}

void            my_mlx_pixel_put(int x, int y, unsigned int color, char *data, int size_line)
{
    char    *dst;
    dst = data + y * size_line + x * 4;
    *(unsigned int*)dst = color;
}

int exita()
{
    exit(0);
}

int where_im(int key, t_cub *cub)
{
	if (key == ESC)
		exit(0);
	if (key == A)
		if (cub->map[(int)(cub->y + cub->cos)][(int)(cub->x - cub->sin)] != '1')
		{
			cub->x -= cub->sin;
			cub->y += cub->cos;
		}
	if (key == W)
		if (cub->map[(int)(cub->y + cub->sin)][(int)(cub->x + cub->cos)] != '1')
		{
			cub->x += cub->cos;
			cub->y += cub->sin;
		}
	if (key == D)
		if (cub->map[(int)(cub->y - cub->cos)][(int)(cub->x + cub->sin)] != '1')
		{
			cub->x += cub->sin;
			cub->y -= cub->cos;
		}
	if (key == S)
		if (cub->map[(int)(cub->y - cub->sin)][(int)(cub->x - cub->cos)] != '1')
		{
			cub->x -= cub->cos;
			cub->y -= cub->sin;
		}
	if (key == LEFT)
		cub->direction += 0.05;
	if (key == RIGHT)
		cub->direction -= 0.05;
	cub->direction = valid_pi(cub->direction);
	cub->cos = cos(cub->direction) * 0.05;
	cub->sin = sin(cub->direction) * 0.05;
	return (0);
}

int color_floor_roof(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (i < cub->width)
	{
		j = 0;
		while (j < cub->height / 2)
		{	
			my_mlx_pixel_put(i, j, 0x56C5FF, cub->data, cub->size_line);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < cub->width)
	{
		j = cub->height / 2;
		while (j < cub->height)
		{	
			my_mlx_pixel_put(i, j, 0x252525, cub->data, cub->size_line);
			j++;
		}
		i++;
	}
	return (0);
}

int drowing_loop(t_cub *cub)
{
	int i;
	int j;
	int x;
	int y;
	
	i = 0;
	color_floor_roof(cub);
	while (cub->map[i])
	{
		j = 0;
		while(cub->map[i][j])
		{
			if (cub->map[i][j] == '1')
				{
				x = 0;
				while (x < 200)
					{
					y = 0;
					while (y < 200)
					{
						my_mlx_pixel_put(i * 200 + x, j * 200 + y, 0x3431fe, cub->data, cub->size_line);
						y++;
					}
					x++;
					}
				}
			j++;
		}
	i++;
	}
	i = cub->x * 200;
	while (i < cub->x * 200 + 15)
	{ 
		j = cub->y * 200;
		while (j < cub->y * 200 + 15)
		{
			my_mlx_pixel_put(i, j, 0x34F800, cub->data, cub->size_line);
			my_mlx_pixel_put(cub->x * 200 - (i - cub->x * 200), j, 0x34F800, cub->data, cub->size_line);
			my_mlx_pixel_put(i, cub->y * 200 - (j - cub->y * 200), 0x34F800, cub->data, cub->size_line);
			my_mlx_pixel_put(cub->x * 200 - (i - cub->x * 200), cub->y * 200 - (j - cub->y * 200), 0x34F800, cub->data, cub->size_line);
			j++;
	}
		i++;
	}
	double xx;
	double yy;
	double d;
	double	opwx;
			double	opwy;
			double	td;
	d = cub->direction + M_PI / 6;
	d = valid_pi(d);
	double t = 0;
	double dist_wall;
	double h_wall;
	double h1;
	double h2;
	i = -1;
	j = 0;
	xx = cub->x;
	yy = cub->y;
int q = 0;
	// while (d > -M_PI / 6 + cub->direction)
	// {

		while (1)
		{
			if (d >= M_PI && d <= 2 * M_PI)
			{	
				if (yy < ceil(cub->y) && yy > floor(cub->y))
					yy = floor(yy);
				else
					yy--;
			}
			else
			{	
				if (yy < ceil(cub->y) && yy > floor(cub->y))
					yy = ceil(yy);
				else
					yy++;
			}
			if (d >= M_PI / 2 && d <= 3 * M_PI / 2)
			{

				if (xx < ceil(cub->x) && xx > floor(cub->x))
					xx = ceil(xx);
				else
					xx++;
			}
			else
			{	
				if (xx < ceil(cub->x) && xx > floor(cub->x))
					xx = floor(xx);
				else
					xx--;
			}
			
			// xx = fabs(xx - cub->x);
			// yy = fabs(yy - cub->y);
		
			// td = d;

			// while (td > M_PI / 2)
			// 	td -= M_PI / 2;
			// if ((d < 2 * M_PI && d > 7 * M_PI / 4) || (d > M_PI / 4  && d < M_PI / 2) ||
			// (d > 3 * M_PI / 4 && d < M_PI) || (d > 5 * M_PI / 4 && d < 3 * M_PI / 2))
			// {
			// 	opwx = 1 / tan(M_PI / 2 - td) * xx;
			// 	opwy = 1 /  tan(td) * yy;
			// }
			// else
			// {
			// 	opwx = tan(M_PI / 2 - td) * xx;
			// 	opwy = tan(td) * yy;
			// }
			// q++;
			// // if (q == 10)
			// // 	exit(1);
			// if (opwx < opwy)
			// { 
			// 	if (d >= 0 && d <= M_PI / 2)
			// 	{write(1, "5\n", 2);
			// 		xx += cub->x;
			// 		yy = cub->y - opwx;
					
			// 	}
			// 	else if (d >= M_PI / 2 && d <= M_PI)
			// 	{write(1, "6\n", 2);
			// 		xx -= cub->x;
			// 		yy = cub->y - opwx;
			// 	}
			// 	else if (d >= M_PI && d <= 3 * M_PI / 2)
			// 	{write(1, "7\n", 2);
			// 		xx -= cub->x;
			// 		yy = cub->y + opwx;
			// 	}
			// 	else
			// 	{write(1, "8\n", 2);
			// 	if ((d < 2 * M_PI && d > 7 * M_PI / 4) || (d > M_PI / 4  && d < M_PI / 2) ||
			// 				(d > 3 * M_PI / 4 && d < M_PI) || (d > 5 * M_PI / 4 && d < 3 * M_PI / 2))
			// 		{
			// 		xx = cub->x - xx;
			// 		yy = cub->y + opwx;
			// 		}
			// 		else
			// 		{
			// 		xx = cub->x - xx;
			// 		yy = cub->y + opwy;
			// 		}
			// 	}	
			// }
			// else
			// {
			// 	if (d >= 0 && d <= M_PI / 2)
			// 	{
			// 		write(1, "1\n", 2);
			// 		yy = cub->y + opwy;
			// 		xx += cub->x;
			// 	}
			// 	else if (d >= M_PI / 2 && d <= M_PI)
			// 	{write(1, "2\n", 2);
			// 		yy -= cub->y;
			// 		xx = cub->x + opwy;
			// 	}
			// 	else if (d >= M_PI && d <= 3 * M_PI / 2)
			// 	{write(1, "3\n", 2);
			// 		yy += cub->y;
			// 		xx = cub->x - opwy;
			// 	}
			// 	else
			// 	{write(1, "4\n", 2);
			// 		if ((d < 2 * M_PI && d > 7 * M_PI / 4) || (d > M_PI / 4  && d < M_PI / 2) ||
			// 				(d > 3 * M_PI / 4 && d < M_PI) || (d > 5 * M_PI / 4 && d < 3 * M_PI / 2))
			// 		{
			// 		yy = cub->y - xx;
			// 		xx = cub->x + opwx;
			// 		}
			// 		else 
			// 		{
			// 		yy = cub->y - yy;
			// 		xx = cub->x + opwy;
			// 		}
				
			// 	}	
			// }
			printf("opwx----%f opxy----%f, d----%f xx----%f yy----%f td----%f\n", opwx, opwy, d, xx, yy, td);
			// if (valid_pi(d) >= M_PI && valid_pi(d) <= 2 * M_PI)
			// {
			// 	if (xx < ceil(xx) && xx > floor(xx))
			// 	{
			// 		if (valid_pi(d) >= M_PI / 2 && valid_pi(d) <= 3 * M_PI / 2)
			// 			xx = ceil(xx);
			// 		else
			// 			xx = floor(xx);
			// 	}
			// 	else
			// 		xx++;
			// 	yy = cub->y - tan(d) * (cub->x - xx);	
			// }
			// else if (valid_pi(d) < M_PI && valid_pi(d) > 0)
			// {
			// if (xx < ceil(xx) && xx > floor(xx))
			// 	{
			// 		if (valid_pi(d) >= M_PI / 2 && valid_pi(d) <= 3 * M_PI / 2)
			// 			xx = ceil(xx);
			// 		else
			// 			xx = floor(xx);
			// 	}
			// 	else
			// 		xx--;
			// 	yy = cub->y - tan(d) * (cub->x - xx);
			// }
			if ((dist_wall = map_wall(xx, yy, cub)) > 0)
			{
					if (valid_pi(d) >= M_PI && valid_pi(d) <= 2 * M_PI)
						while (xx > cub->x)
						{
							i = xx * 200;
							j =  200 * yy;
							if (i > cub->width - 1 || j > cub->height - 1 || j < 0 || i < 0)
								break ;
							my_mlx_pixel_put(i, j, 0x7000DD, cub->data, cub->size_line);
							if ((d < 2 * M_PI && d > 7 * M_PI / 4) || (d > M_PI / 4  && d < M_PI / 2) ||
							(d > 3 * M_PI / 4 && d < M_PI) || (d > 5 * M_PI / 4 && d < 3 * M_PI / 2))
							{
								xx -= 0.005 * sin(td);
								yy += 0.005 * cos(td);
							}
							else
							{
								xx -= 0.005 * sin(td);
								yy += 0.005 * cos(td);
							}
					
						
						}
				break;
			}
		}
	// 	d -= M_PI / 3 / cub->width;
	
	// }
	// while (d > -M_PI / 6)
	// {
	// 	t = 0;
	// 	while (1)
	// 	{
			
	// 		xx = cub->x + t * cos(cub->direction + d);
	// 		yy = cub->y + t * sin(cub->direction + d);
	// 		if ((dist_wall = map_wall(xx, yy, cub)) > 0)
	// 		{
	// 			i++;
	// 			dist_wall = dist_wall * cos(d);
	// 			h_wall = cub->height / 2;
	// 			h_wall = h_wall / tan((60 / 2) * (M_PI / 180));
	// 			h_wall = ceil(h_wall / dist_wall);
	// 			j =  (cub->height - h_wall) / 2;
	// 			if (h_wall > cub->width)
	// 				h_wall = cub->width;
	// 			while (j < (cub->height + h_wall) / 2)
	// 			{
	// 				if (j < 0)
	// 					j = 0;
	// 				if (j > cub->height)
	// 					break ;
	// 					my_mlx_pixel_put(i, j, 0x7000DD, cub->data, cub->size_line);
	// 				j++;
	// 			}
	// 			break;
				
	// 		}
	// 		if (i > cub->width - 1)
	// 				break;
	// 		t += 0.005;
	// 	}
	// 	d -= M_PI / 3 / cub->width;
	
	// }
		mlx_put_image_to_window(cub->mlx, cub->mlx_win, cub->image, 0, 0);
	return (0);
}




int main () 
{
	t_cub *cub;
	cub = (t_cub *)malloc(sizeof(t_cub));
	set_all(cub);
	int i = 0;
	int j = 0;
	int k = 0;
	int z = 0;
	char **line;
	g_i = 0;
	g_j = 0;
	line = (char **)malloc(7 * sizeof(char *));
	while (i != 6)
	{
		line[i] = (char *)malloc(9);
		i++;
	}
	line[0] = "111111";
	line[1] = "1N0001";
	line[2] = "100001";
	line[3] = "100001";
	line[4] = "100001";
	line[5] = "111111";
	line[6] = 0;
	i = 0;
	cub->map = line;

	while (g_i == 0 && line[i] != 0)
	{
		j = 0;
		while(line[i][j] && g_i == 0)
		{
			if (line[i][j] == 'N' || line[i][j] == 'E' || line[i][j] == 'S' || line[i][j] == 'W')
			{
				cub->x = i + 0.5;
				cub->y = j + 0.5;
				g_i++;
				if (line[i][j] == 'N')
					cub->direction = 3 * M_PI / 2;
				else if (line[i][j] == 'E')
						cub->direction = 0;
				else if (line[i][j] == 'S')
					cub->direction = M_PI / 2;
				else if (line[i][j] == 'W')
					cub->direction = M_PI;
			}
			j++;
		}
		i++;
	}
 	mlx_hook(cub->mlx_win, 2, 1L << 0, where_im, cub);
	mlx_hook(cub->mlx_win, 3, 1L << 1, where_im, cub);
    mlx_hook(cub->mlx_win, 17, 1L << 17, exita, 0);
	mlx_loop_hook(cub->mlx, drowing_loop, cub);
    mlx_loop(cub->mlx);
    free(cub);
}
