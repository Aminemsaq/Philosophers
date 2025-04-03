/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:12:37 by amsaq             #+#    #+#             */
/*   Updated: 2025/04/02 19:12:38 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "philo.h"

long	get_time(void)
{
	struct timeval	time;
	long			ms;

	gettimeofday(&time, NULL);
	ms = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (ms);
}

void	ft_usleep(long ms)
{
	long	end;

	end = get_time() + ms;
	while (get_time() < end)
		usleep(50);
}

void	print_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%ld ms %d %s\n", get_time() - philo->data->time, philo->id + 1, str);
	pthread_mutex_unlock(&philo->data->print);
}

int	check_eating(t_philo *philo)
{
	int	i;

	i = -1;
	if (philo->data->nbr_of_must_eat < 0)
		return (1);
	while (++i < philo->data->nbr_of_philo)
	{
		if (philo[i].count_eat != philo[i].num_eat)
			return (1);
	}
	return (0);
}
