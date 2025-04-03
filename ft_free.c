/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:07:51 by amsaq             #+#    #+#             */
/*   Updated: 2025/04/03 09:27:42 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_of_philo)
		pthread_mutex_destroy(&data->forks[i]);
	free(data->forks);
	free(data->philos);
	pthread_mutex_destroy(&data->print);
}
