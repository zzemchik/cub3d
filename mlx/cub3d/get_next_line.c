#include "cub3d.h"

void	is_str(char **temp, char **after_n, char **line, char **str)
{
	*temp = *after_n;
	*after_n = find_new_line(*str);
	if (*temp)
		free(*temp);
	*temp = *line;
	*line = ft_strjoin(*line, *str);
	if (*temp)
		free(*temp);
	free(*str);
	*str = ft_strdup(*after_n);
}

int		some_read(char **buff, char **line, char **after_n, int fd)
{
	int		count;
	char	*temp;

	count = 1;
	while (count > 0)
	{
		count = read(fd, *buff, 100);
		(*buff)[count] = 0;
		temp = *after_n;
		*after_n = find_new_line(*buff);
		if (temp)
			free(temp);
		temp = *line;
		*line = ft_strjoin(*line, *buff);
		if (temp)
			free(temp);
		if (*after_n != 0)
			break ;
	}
	return (count);
}

int		some_func(char **str, char **after_n, char **buff, int count)
{
	free(*str);
	*str = ft_strdup(*after_n);
	free(*buff);
	if (*after_n)
		free(*after_n);
	if (*str == 0 && count == 0)
		return (0);
	if (*str == 0 && count != 0)
		return (-1);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static char	*str;
	int			c;
	char		*buff;
	char		*after_n;
	char		*temp;

	c = 1;
	if ((c = read(fd, &c, 0)) == -1 || fd < 0 ||
	line == 0 || !(buff = (char *)malloc(101)))
		return (-1);
	if ((*line = 0) && !str)
		if (!(str = ft_strdup("")))
			return (-1);
	if (((after_n = 0) == 0) && str != 0 && *(str) != 0)
	{
		is_str(&temp, &after_n, line, &(str));
		if (after_n)
		{
			free(buff);
			free(after_n);
			return (1);
		}
	}
	c = some_read(&buff, line, &after_n, fd);
	return (some_func(&str, &after_n, &buff, c));
}
