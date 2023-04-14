/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:21:38 by yamarach          #+#    #+#             */
/*   Updated: 2023/03/11 13:08:12 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*lire(char *av)
{
	int		fd;
	char	*str;
	char	*line;

	if (!check_ber(av))
		return (NULL);
	str = NULL;
	fd = open(av, O_RDWR);
	if (fd == -1)
	{
		write(2, "open error\n", 11);
		return (0);
	}
	line = get_next_line(fd);
	while (line)
	{
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	close(fd);
	return (str);
}

char	**lire2(char *av)
{
	int		fd;
	char	*str;
	char	*line;
	char	**map;

	str = NULL;
	fd = open(av, O_RDWR);
	if (fd == -1)
		return (write(2, "open error\n", 11), (NULL));
	line = get_next_line(fd);
	while (line)
	{
		str = ft_strjoin(str, line);
		free(line);
		line = get_next_line(fd);
	}
	if (!check_twoligne(av))
		return (0);
	if (line)
		free(line);
	close(fd);
	map = to_split(str);
	free(str);
	return (map);
}

int	ft_parsing(char *av)
{
	char	**map;
	char	*str;
	t_point	*pose;
	t_point	*size;
	int		i;

	i = 0;
	pose = NULL;
	pose = malloc(sizeof(t_point));
	size = NULL;
	size = malloc(sizeof(t_point));
	str = lire(av);
	if (!str || !size || !pose)
		return (ft_frip3(str, pose, size), (0));
	if (!*str || str[0] == '\n')
		return (write (2, "Error\nSpace\n", 12), ft_frip3(str, pose, size), (0));
	map = to_split(str);
	if (!map)
		return (ft_frip2(map, pose, size), (0));
	pose = started(map, pose);
	size = size_map(map, size);
	if (!anafull(str, map, pose, size))
		return (0);
	return (ft_frip(map, pose, size), (1));
}

char	**to_split(char *str)
{
	char	**map;

	if (!str)
		return (NULL);
	map = ft_split(str, '\n');
	return (map);
}

int	line_analyse(char **str)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	if (!pec(str, p, e, c))
		return (0);
	return (1);
}
