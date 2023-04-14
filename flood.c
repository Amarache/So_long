/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:17:04 by yamarach          #+#    #+#             */
/*   Updated: 2023/03/04 13:48:19 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**f_fill(char **map, t_point size, int row, int col)
{
	if (row <= 0 || col <= 0 || row > size.x || col > size.y)
		return (NULL);
	if (map[row][col] == 'X' || map[row][col] == '1' || map[row][col] == 'E')
		return (NULL);
	map[row][col] = 'X';
	f_fill(map, size, row - 1, col);
	f_fill(map, size, row + 1, col);
	f_fill(map, size, row, col - 1);
	f_fill(map, size, row, col + 1);
	return (map);
}

int	flood_fill(char **map, t_point *size, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	map = f_fill(map, *size, x, y);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			if (map[i][j] == 'E' && (map[i + 1][j] != 'X' && map[i
					- 1][j] != 'X' && map[i][j + 1] != 'X' && map[i][j
					- 1] != 'X'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

t_point	*started(char **str, t_point *pose)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				pose->x = i;
				pose->y = j;
			}
			j++;
		}
		i++;
	}
	return (pose);
}
