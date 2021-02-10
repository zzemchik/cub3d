/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 17:30:49 by rnancee           #+#    #+#             */
/*   Updated: 2021/02/10 20:42:22 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include "mlx.h"

# define ESC	53
# define W		13
# define A		0
# define S		1
# define D		2
# define LEFT	123
# define RIGHT	124
# define EPS	0.000000001

typedef struct		s_list
{
	char			*line;
	struct s_list	*next;

}					t_list;

typedef	struct		s_texture
{
	int				size_line;
	void			*texture;
	char			*add_texture;
	char			*name_texture;
	int				width;
	int				height;
}					t_texture;

typedef	struct		s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef	struct		s_keys
{
	char			w;
	char			a;
	char			s;
	char			d;
	char			right;
	char			left;
}					t_keys;

typedef	struct		s_sprite_tx
{
	int				j;
	unsigned int	color;
	double			y_texture;
	double			max;
	double			x_texture;
	int				i;
}					t_sprite_tx;

typedef	struct		s_draw_wall
{
	double			h_wall;
	double			kall;
	double			max;
	double			hit;
}					t_draw_wall;

typedef	struct		s_ray
{
	double			xx;
	double			yy;
	double			dx;
	double			dy;
	double			b_1;
	double			a_1;
	double			a_gip;
	double			b_gip;
	int				iter;
}					t_ray;

typedef struct		s_cub
{
	unsigned int	color_floor;
	unsigned int	color_ceil;
	double			*dist;
	void			*mlx;
	void			*mlx_win;
	void			*mlx_tex;
	int				width;
	int				height;
	void			*image;
	char			**map;
	char			*data;
	char			*map_file;
	int				size_line;
	int				sprite_num;
	int				bpp;
	int				*sprite_x;
	int				*sprite_y;
	double			hit;
	double			hit_sprite;
	double			dist_wall;
	double			*dist_sprite;
	double			cos;
	double			sin;
	double			x;
	double			y;
	double			direction;
	double			fov;
	double			*dist_wall_all;
	int				what_texture;
	t_color			ceil;
	t_color			floor;
	t_texture		no;
	t_texture		so;
	t_texture		we;
	t_texture		ea;
	t_texture		sp;
	t_keys			keys;
	t_list			*lst;
}					t_cub;
int					g_error;
void				drow_wall(t_cub *cub, int i);
char				*give_color(t_cub *cub, double kall, double hit);
void				my_mlx_pixel_put(int x, int y, \
					unsigned int color, t_cub *cub);
void				drow_sprite(t_cub *cub, int k);
size_t				ft_strlen(const char *str);
double				valid_pi(double dir);
int					key_release(int key, t_cub *cub);
int					key_press(int key, t_cub *cub);
int					search_wall(t_cub *cub);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strdup(const char *str);
char				*find_new_line(char *buff);
int					get_next_line(int fd, char **line);
void				ft_lstadd_back(t_list **lst, t_list *lst_new);
int					ft_lstsize(t_list *lst);
void				what_in_line(char *line, t_cub *cub);
t_list				*ft_lstnew(char *content);
t_list				*ft_lstlast(t_list *lst);
void				all_set(t_cub *cub);
void				all_free(t_cub *cub);
void				valid_map(t_cub *cub);
int					ft_atoi_cub(const char *str, int *i);
int					skip_spaces(const char *line, int i);
void				parser(t_cub *cub);
void				set_all(t_cub *cub);
void				where_sprite(t_cub *cub, int i);
void				drow_sprite_tx(t_cub *cub, int size, \
					int point_sprite, double dist_sprite);
void				valid_texture(char *texture);
void				valid_ceil_floor(char *str, t_color *a, int i);
void				movement(t_cub *cub);
int					scr_sh(t_cub *cub);
int					exita(t_cub *cub);
int					dist_a(t_cub *cub, t_ray *ray, int *uu);
int					dist_b(t_cub *cub, t_ray *ray, int *ll);
void				error_1(t_cub *cub);
#endif
