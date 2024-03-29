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
		if (lst_cpy->line)
			free(lst_cpy->line);
		if (lst_cpy)
			free(lst_cpy);
	}
	cub->map[i] = 0;
	i = -1;
	while (cub->map[++i] != 0)
		space_map(&cub->map[i], size_len_max, ft_strlen(cub->map[i]));
}

void	parser(t_cub *cub)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(cub->map_file, O_RDONLY);
	while ((i = get_next_line(fd, &line)) != 0 && g_error == 0)
	{
		if (i == -1)
		{
			g_error = 1;
			break ;
		}
		what_in_line(line, cub);
		if (line)
			free(line);
	}
	what_in_line(line, cub);
	if (line)
		free(line);
	close(fd);
	if (g_error == 0)
	{
		norm_parser(cub, i);
		valid_map(cub);
	}
}
