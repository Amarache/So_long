/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:32:24 by yamarach          #+#    #+#             */
/*   Updated: 2023/03/11 13:08:08 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = ft_strlen(str);
	i -= 4;
	if (str[i] != '.' || str[i + 1] != 'b'
		|| str[i + 2] != 'e' || str[i + 3] != 'r')
	{
		write(2, "Error\nMAP\n", 10);
		return (0);
	}
	return (1);
}

void	anime(t_vars *all, char **map)
{
	if (finish(map))
	{
		if (all->exit)
			mlx_destroy_image(all->mllx->mlx, all->exit);
		all->exit = mlx_xpm_file_to_image(all->mllx->mlx,
				"./assets/sprites/dg.xpm", &all->img_width, &all->img_height);
	}
	mlx_string_put(all->mllx->mlx, all->mllx->win, 7, 20, 0xFFFFFF, "nb");
}

int	affnb(t_vars *all)
{
	char	*nbr;

	nbr = ft_itoa(all->nb);
	mlx_string_put(all->mllx->mlx, all->mllx->win, 7, 20, 0xFFFFFF, nbr);
	free(nbr);
	return (0);
}

int	anafull(char *str, char **map, t_point *pose, t_point *size)
{
	int	i;

	i = 0;
	while (str[++i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n'))
			return ((ft_frip(map, pose, size)), free(str),
				(write(2, "Error\nempty line\n", 17), (0)));
	}
	free(str);
	if (!line_analyse(map))
		return ((ft_frip(map, pose, size)),
			(write(2, "Error\nelement\n", 14), (0)));
	else if (!check_form(map))
		return ((ft_frip(map, pose, size)),
			(write(2, "Error\nform\n", 11), (0)));
	else if (!periphe(map))
		return ((ft_frip(map, pose, size)),
			(write(2, "Error\nborder\n", 13), (0)));
	else if (!flood_fill(map, size, pose->x, pose->y))
		return ((ft_frip(map, pose, size)),
			(write(2, "Error\nexit\n", 11), (0)));
	return (1);
}

int	check_twoligne(char *av)
{
	int		fd;
	char	c;

	fd = open(av, O_RDWR);
	if ((read(fd, &c, 1)) < 1)
	{
		write(2, "Map vide\n", 9);
		return (0);
	}
	close(fd);
	return (1);
}
