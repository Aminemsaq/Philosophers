/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:13:14 by amsaq             #+#    #+#             */
/*   Updated: 2025/04/07 18:09:38 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (printf("Error: Wrong number of arguments.\n"), 1);
	if (!ft_parsing(ac, av))
		return (printf("Error: Wrong type of arguments.\n"), 1);
	if (init_data(&data, ac, av) || init_mutexes(&data) || init_philos(&data))
		return (cleanup(&data),printf("Error during initialization\n"));
	start_simulation(&data);
	cleanup(&data);
	
}
