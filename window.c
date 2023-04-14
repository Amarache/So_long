/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 14:42:21 by yamarach          #+#    #+#             */
/*   Updated: 2023/04/14 15:39:15 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	show_wind(t_vars *all)
{
	all->nb = 0;
	all->mllx->mlx = mlx_init();
	if (!imp_image_to_window(all))
	{
		write(1, "Error\nxpm\n", 10);
		return (0);
	}
	all->size = size_map(all->map, all->size);
	all->mllx->win = mlx_new_window(all->mllx->mlx, (all->size->y * 32),
			(all->size->x * 32), "Bladee univers <3!");
	render(all);
	mlx_key_hook(all->mllx->win, &walk, all);
	mlx_hook(all->mllx->win, 1, 1L << 0, &walk, all);
	mlx_hook(all->mllx->win, 17, 0, &mlx_loop_end, all->mllx->mlx);
	mlx_loop_hook(all->mllx->mlx, &affnb, all);
	mlx_loop(all->mllx->mlx);
	return (1);
}

void	render(t_vars *all)
{
	int	x;
	int	y;

	x = -1;
	while (all->map[++x])
	{
		y = -1;
		while (all->map[x][++y])
		{
			if (all->map[x][y] == '1')
				render_util(all, '1', y, x);
			else if (all->map[x][y] == '0')
				render_util(all, '0', y, x);
			else if (all->map[x][y] == 'P')
				render_util(all, 'P', y, x);
			else if (all->map[x][y] == 'E')
				render_util(all, 'E', y, x);
			else if (all->map[x][y] == 'C')
				render_util(all, 'C', y, x);
		}
	}
}

int	walk(int keycode, t_vars *all)
{
	all->pose = started(all->map, all->pose);
	if (keycode == 65307)
	{
		end_game(all);
		exit(0);
	}
	if (check_finish(keycode, all) && finish(all->map))
	{
		moveplus(all);
		end_game(all);
		exit(0);
	}
	else
		can_walk(keycode, all);
	anime(all, all->map);
	render(all);
	return (0);
}

char	*img_case(char c)
{
	if (!c)
		return (NULL);
	else if (c == '0')
		return ("./assets/sprites/ciel.xpm");
	else if (c == '1')
		return ("./assets/sprites/wall.xpm");
	else if (c == 'P')
		return ("./assets/sprites/ku.xpm");
	else if (c == 'E')
		return ("./assets/sprites/cado.xpm");
	else if (c == 'C')
		return ("./assets/sprites/cle2.xpm");
	return ("./assets/sprites/void.wall");
}

int	imp_image_to_window(t_vars *all)
{
	ft_null(all);
	all->wall = mlx_xpm_file_to_image(all->mllx->mlx,
			"./assets/sprites/wall.xpm", &all->img_width, &all->img_height);
	if (!all->wall)
		return (0);
	all->vide = mlx_xpm_file_to_image(all->mllx->mlx,
			"./assets/sprites/ciel.xpm", &all->img_width, &all->img_height);
	if (!all->vide)
		return (0);
	all->play = mlx_xpm_file_to_image(all->mllx->mlx,
			"./assets/sprites/bladee.xpm", &all->img_width, &all->img_height);
	if (!all->play)
		return (0);
	all->exit = mlx_xpm_file_to_image(all->mllx->mlx,
			"./assets/sprites/cado.xpm", &all->img_width, &all->img_height);
	if (!all->exit)
		return (0);
	all->coin = mlx_xpm_file_to_image(all->mllx->mlx,
			"./assets/sprites/cle2.xpm", &all->img_width, &all->img_height);
	if (!all->coin)
		return (0);
	return (1);
}
