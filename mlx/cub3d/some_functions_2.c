/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnancee <rnancee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 13:32:55 by rnancee           #+#    #+#             */
/*   Updated: 2021/01/17 20:45:38 by rnancee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_atoi_cub(const char *str, int *i)
{
	int k;
	int num;

	k = 1;
	num = 0;
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == '-' && ((*i)++))
		k = -1;
	while (str[*i] <= '9' && str[*i] >= '0')
	{
		num = 10 * num + (str[*i] - '0');
		(*i)++;
		if (num > 10000)
			break ;
	}
	while (str[*i] <= '9' && str[*i] >= '0')
		(*i)++;
	return(num * k);

}

int	skip_spaces(const char *line, int i)
{
	while (line[i] == ' ')
		i++;
	return i;
}