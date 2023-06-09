/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yamarach < yamarach@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:49:38 by yamarach          #+#    #+#             */
/*   Updated: 2023/03/04 13:49:01 by yamarach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	int	ft_nbrint(int n)
{
	int	i;

	i = (n < 0);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*increment_char(char *dest, long tmp, long j, int signe)
{
	int	i;

	i = 0;
	while (i < j - 1 - signe)
	{
		dest[(j - 2) - i] = (tmp % 10) + 48;
		tmp = tmp / 10;
		i++;
	}
	dest[j - 1] = '\0';
	return (dest);
}

char	*ft_itoa(int nb)
{
	char	*dest;
	long	j;
	int		signe;
	long	tmp;

	signe = 0;
	tmp = (long)nb;
	j = ft_nbrint(tmp) + 1;
	dest = (char *)malloc(sizeof(char) * (ft_nbrint(tmp) + 1));
	if (!dest)
		return (NULL);
	if (nb < 0)
	{
		tmp = (tmp * -1);
		dest[0] = '-';
		signe = 1;
	}
	return (increment_char(dest, tmp, j, signe));
}
