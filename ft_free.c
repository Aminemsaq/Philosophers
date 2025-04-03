/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:07:51 by amsaq             #+#    #+#             */
/*   Updated: 2025/04/02 19:22:06 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data *data)
{
	int	i;

	// Destroy mutexes
	i = -1;
	while (++i < data->nbr_of_philo)
		pthread_mutex_destroy(&data->forks[i]);

	// Free allocated memory
	free(data->forks);
	free(data->philos);

	// Destroy the print mutex
	pthread_mutex_destroy(&data->print);
}
