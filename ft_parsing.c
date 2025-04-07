/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:10:55 by amsaq             #+#    #+#             */
/*   Updated: 2025/04/05 12:15:41 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(const char *str)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	if (!str[i])
		return (-1);
	while (str[i])
	{
		if (result > (LONG_MAX / 10) || (result == (LONG_MAX / 10) && str[i]
				- '0' > LONG_MAX % 10))
			return (-1);
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (result > INT_MAX)
		return (-1);
	return (result);
}

int	ft_check(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_atol(av[i]) < 1)
			return (0);
	}
	return (1);
}

int	ft_parsing(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	if (ft_check(ac, av) == 0)
		return (0);
	return (1);
}
