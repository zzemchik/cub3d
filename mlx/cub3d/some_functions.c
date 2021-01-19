/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:53:19 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/18 10:42:19 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_strlen(const char *str)
{
	char	*str_cpy;
	size_t	i;

	if (str == 0)
		return (0);
	str_cpy = (char *)str;
	i = 0;
	while (*(str_cpy++) != '\0')
		i++;
	return (i);
}


double	valid_pi(double dir)
{
	while (dir > 2 * M_PI)
		dir -= 2 * M_PI;
	while (dir < 0)
		dir += 2 * M_PI;
	return (dir);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	a;
	size_t	b;
	size_t	d;
	char	*c;

	a = 0;
	b = 0;
	if (s1 != 0)
		a = ft_strlen(s1);
	if (s2 != 0)
		b = ft_strlen(s2);
	d = a;
	c = (char *)malloc(a + b + 1);
	if (c == 0)
	{
		g_error = 1;
		return (0);
	}
	c[a + b] = 0;
	if (s1 != 0)
		while (a--)
			c[a] = s1[a];
	if (s2 != 0)
		while (b--)
			c[d + b] = s2[b];
	return (c);
}

char	*ft_strdup(const char *str)
{
	char	*str_cpy;
	size_t	i;

	if (str == 0)
		return (0);
	i = ft_strlen(str);
	str_cpy = (char *)malloc(i + 1);
	if (str_cpy == 0)
	{
		g_error = 1;
		return (0);
	}
	str_cpy[i] = 0;
	i = 0;
	while (*str != 0)
	{
		str_cpy[i] = *str;
		i++;
		str++;
	}
	return (str_cpy);
}

char	*find_new_line(char *buff)
{
	int i;

	i = -1;
	while (buff[++i] != 0)
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			return (ft_strdup(&buff[i + 1]));
		}
	return (0);
}
