/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:25:46 by yamarach          #+#    #+#             */
/*   Updated: 2023/03/11 13:36:09 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av, char **envi)
{
	t_vars	*all;

	if (!envi[0] || !envi[5])
		return (0);
	if (ac == 2)
	{
		if (!ft_parsing(av[1]))
			return (0);
		all = NULL;
		all = malloc(sizeof(t_vars));
		all->pose = malloc(sizeof(t_point));
		all->size = malloc(sizeof(t_point));
		all->mllx = malloc(sizeof(t_mllx));
		if (!all || !all->pose || !all->size || !all->mllx)
			return (0);
		all->map = lire2(av[1]);
		if (!all->map)
			return (0);
		show_wind(all);
		end_game(all);
	}
	return (1);
}
