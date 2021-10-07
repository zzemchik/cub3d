#include "cub3d.h"

void		valid_texture(char *texture)
{
	int i;
	int k;

	k = 0;
	i = ft_strlen(texture);
	if (texture[0] != '.' || texture[1] != '/' || texture[i - 1] != 'm' ||
	texture[i - 2] != 'p' || texture[i - 3] != 'x' || texture[i - 4] != '.')
		g_error = 2;
	while (--i)
		if (texture[i] == '.' || texture[i] == '/')
			k++;
	if (k != 2)
		g_error = 2;
}

int			valid_ceil_floor_norm(t_color *a, char *str)
{
	int i;

	i = 1;
	a->r = ft_atoi_cub(str, &i);
	i = skip_spaces(str, i) + 1;
	a->g = ft_atoi_cub(str, &i);
	i = skip_spaces(str, i) + 1;
	a->b = ft_atoi_cub(str, &i);
	return (i - 1);
}

void		valid_ceil_floor(char *str, t_color *a, int i)
{
	int k;

	k = 0;
	while (str[++i] != 0)
	{
		if ((str[i] <= '9' && str[i] >= '0') || str[i] == ' ' || str[i] == ',')
		{
			if (str[i] == ',')
				k++;
			continue;
		}
		g_error = 1;
		break ;
	}
	if (k != 2 || a->r != -1)
		g_error = 1;
	i = valid_ceil_floor_norm(a, str);
	if (a->r < 0 || a->r > 255 || a->g < 0 || \
	a->g > 255 || a->b < 0 || a->b > 255)
		g_error = 1;
	while (str[++i] != 0)
		if (str[i] != ' ')
			g_error = 1;
}
