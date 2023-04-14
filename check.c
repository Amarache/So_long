/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:32:11 by yamarach          #+#    #+#             */
/*   Updated: 2023/03/05 14:01:22 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_finish(int keycode, t_vars *all)
{
	if (keycode == KEY_W && all->map[all->pose->x - 1][all->pose->y] == 'E')
		return (1);
	else if (keycode == KEY_S && all->map[all->pose->x
			+ 1][all->pose->y] == 'E')
		return (1);
	else if (keycode == KEY_A && all->map[all->pose->x][all->pose->y
		- 1] == 'E')
		return (1);
	else if (keycode == KEY_D && all->map[all->pose->x][all->pose->y
		+ 1] == 'E')
		return (1);
	return (0);
}

void	can_walk(int keycode, t_vars *all)
{
	if (keycode == KEY_W && all->map[all->pose->x - 1][all->pose->y] != '1'
		&& all->map[all->pose->x - 1][all->pose->y] != 'E')
		movekey(keycode, all);
	else if (keycode == KEY_S && all->map[all->pose->x + 1][all->pose->y] != '1'
			&& all->map[all->pose->x + 1][all->pose->y] != 'E')
		movekey(keycode, all);
	else if (keycode == KEY_A && all->map[all->pose->x][all->pose->y - 1] != '1'
			&& all->map[all->pose->x][all->pose->y - 1] != 'E')
		movekey(keycode, all);
	else if (keycode == KEY_D && all->map[all->pose->x][all->pose->y + 1] != '1'
			&& all->map[all->pose->x][all->pose->y + 1] != 'E')
		movekey(keycode, all);
}

void	movekey(int key, t_vars *all)
{
	if (key == KEY_W)
	{
		all->map[all->pose->x][all->pose->y] = '0';
		all->map[all->pose->x - 1][all->pose->y] = 'P';
		moveplus(all);
	}
	if (key == KEY_S)
	{
		all->map[all->pose->x][all->pose->y] = '0';
		all->map[all->pose->x + 1][all->pose->y] = 'P';
		moveplus(all);
	}
	if (key == KEY_A)
	{
		all->map[all->pose->x][all->pose->y] = '0';
		all->map[all->pose->x][all->pose->y - 1] = 'P';
		moveplus(all);
	}
	if (key == KEY_D)
	{
		all->map[all->pose->x][all->pose->y] = '0';
		all->map[all->pose->x][all->pose->y + 1] = 'P';
		moveplus(all);
	}
}

int	finish(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	moveplus(t_vars *all)
{
	all->nb++;
	write(1, "move cont : ", 12);
	ft_putnbr(all->nb);
	write(1, "\n", 1);
}
