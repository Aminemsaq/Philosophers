/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:13:14 by amsaq             #+#    #+#             */
/*   Updated: 2025/04/04 11:33:07 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{

	if (ac < 5 || ac > 6)
	{
		printf("Error: Wrong number of arguments.\n");
		return (1);
	}
	if (!ft_parsing(ac, av))
		return (printf("Error: Wrong type of arguments.\n"));
}
