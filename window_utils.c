/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 12:10:28 by yamarach          #+#    #+#             */
/*   Updated: 2023/03/11 13:03:53 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_util(t_vars *all, char c, int y, int x)
{
	if (c == '1')
		mlx_put_image_to_window(all->mllx->mlx,
			all->mllx->win, all->wall, y * 32, x * 32);
	else if (c == '0')
		mlx_put_image_to_window(all->mllx->mlx,
			all->mllx->win, all->vide, y * 32, x * 32);
	else if (c == 'P')
		mlx_put_image_to_window(all->mllx->mlx,
			all->mllx->win, all->play, y * 32, x * 32);
	else if (c == 'E')
		mlx_put_image_to_window(all->mllx->mlx,
			all->mllx->win, all->exit, y * 32, x * 32);
	else if (c == 'C')
		mlx_put_image_to_window(all->mllx->mlx,
			all->mllx->win, all->coin, y * 32, x * 32);
}

void	ft_null(t_vars *all)
{
	all->wall = NULL;
	all->vide = NULL;
	all->play = NULL;
	all->exit = NULL;
	all->coin = NULL;
	all->mllx->win = NULL;
}
