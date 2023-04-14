/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 12:47:39 by yamarach          #+#    #+#             */
/*   Updated: 2023/03/11 13:13:55 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_ptr(void **ptr)
{
	if (ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int	end_game(t_vars *all)
{
	int	i;

	mlx_loop_end(all->mllx->mlx);
	if (all->vide)
		mlx_destroy_image(all->mllx->mlx, all->vide);
	if (all->wall)
		mlx_destroy_image(all->mllx->mlx, all->wall);
	if (all->play)
		mlx_destroy_image(all->mllx->mlx, all->play);
	if (all->exit)
		mlx_destroy_image(all->mllx->mlx, all->exit);
	if (all->coin)
		mlx_destroy_image(all->mllx->mlx, all->coin);
	if (all->mllx->win)
	{
		mlx_clear_window(all->mllx->mlx, all->mllx->win);
		mlx_destroy_window(all->mllx->mlx, all->mllx->win);
	}
	if (all->mllx->mlx)
		mlx_destroy_display(all->mllx->mlx);
	i = -1;
	while (all->map[++i])
		free(all->map[i]);
	return (free(all->map), free(all->pose), (free(all->size),
			free(all->mllx->mlx), free(all->mllx), free(all), (0)));
}

void	ft_frip(char **map, t_point *pose, t_point *size)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	free(pose);
	pose = NULL;
	free(size);
	size = NULL;
}

void	ft_frip2(char **map, t_point *pose, t_point *size)
{
	free(map);
	free(pose);
	pose = NULL;
	free(size);
	size = NULL;
}

void	ft_frip3(char *str, t_point *pose, t_point *size)
{
	free(str);
	free(pose);
	pose = NULL;
	free(size);
	size = NULL;
}
