/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 17:06:36 by yamarach          #+#    #+#             */
/*   Updated: 2023/03/05 14:47:42 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_form(char **str)
{
	int	i;
	int	l;
	int	h;

	i = 0;
	l = 0;
	h = 0;
	if (!str)
		return (0);
	l = ft_strlen(str[0]);
	while (str[i])
	{
		if (ft_strlen(str[i]) != l)
			return (0);
		i++;
	}
	while (str[h])
		h++;
	if (l <= h)
		return (0);
	return (1);
}

int	periphe(char **str)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (str[x])
		x++;
	while (str[0][i])
	{
		if (str[0][i] != '1')
			return (0);
		if (str[x - 1][i] != '1')
			return (0);
		i++;
	}
	j = 0;
	while (str[j])
	{
		if (str[j][0] != '1' || str[j][ft_strlen(str[j]) - 1] != '1')
			return (0);
		j++;
	}
	return (1);
}

t_point	*size_map(char **map, t_point *size)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		i++;
	}
	size->x = i;
	size->y = j;
	return (size);
}

int	pec(char **str, int p, int e, int c)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = -1;
		while (str[i][++j])
		{
			if (str[i][j] != '0' && str[i][j] != '1' && str[i][j] != 'C'
				&& str[i][j] != 'E' && str[i][j] != 'P' && str[i][j] != '\n')
				return (0);
			if (str[i][j] == 'P')
				p++;
			if (str[i][j] == 'E')
				e++;
			if (str[i][j] == 'C')
				c++;
		}
	}
	if (p != 1 || e != 1 || c < 1)
		return (0);
	return (1);
}
