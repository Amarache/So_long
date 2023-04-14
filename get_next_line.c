/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:13:34 by yamarach          #+#    #+#             */
/*   Updated: 2023/03/04 13:49:42 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_nl(char *str)
{
	if (str[0] == '\n')
		return (1);
	return (0);
}

char	*ft_returline(char *statique)
{
	int		i;
	int		j;
	char	*linefinal;

	i = 0;
	j = 0;
	if (!statique || !statique[0])
		return (NULL);
	while (statique[i] && statique[i] != '\n')
		i++;
	i += if_bn(&statique[i]);
	linefinal = malloc(sizeof(char) * i + 1);
	if (!linefinal)
		return (NULL);
	while (j <= i - 1)
	{
		linefinal[j] = statique[j];
		j++;
	}
	linefinal[j] = '\0';
	return (linefinal);
}

char	*ft_returnrest(char *statique)
{
	char	*new_static;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (statique == NULL)
		return (NULL);
	while (statique[i] && statique[i] != '\n')
		i++;
	if (statique[i] == '\0')
		return (ft_free(statique));
	i += ft_check_nl(&statique[i]);
	new_static = malloc(sizeof(char) * (ft_strlen(statique) - i + 1));
	if (!new_static)
		return (NULL);
	while (statique[i])
		new_static[j++] = statique[i++];
	new_static[j] = '\0';
	free(statique);
	statique = NULL;
	return (new_static);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*statique[SIZE_MAX];
	int			ret;
	char		*lineretur;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!if_bn(statique[fd]) && ret != 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret == -1)
			return (ft_free(buffer));
		buffer[ret] = '\0';
		statique[fd] = ft_strjoin(statique[fd], buffer);
	}
	free (buffer);
	lineretur = ft_returline(statique[fd]);
	statique[fd] = ft_returnrest(statique[fd]);
	return (lineretur);
}
