/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:13:14 by amsaq             #+#    #+#             */
/*   Updated: 2025/04/03 09:29:58 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2)
		ft_usleep(40);
	while (1)
	{
		pthread_mutex_lock(&philo->data->forks[philo->id]);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(&philo->data->forks[philo->id_next]);
		print_message(philo, "has taken a fork");
		philo->last_eat = get_time();
		print_message(philo, "is eating");
		if (philo->count_eat != philo->num_eat
			&& philo->data->nbr_of_must_eat > 0)
			philo->count_eat++;
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->data->forks[philo->id]);
		pthread_mutex_unlock(&philo->data->forks[philo->id_next]);
		print_message(philo, "is sleeping");
		ft_usleep(philo->data->time_to_sleep);
		print_message(philo, "is thinking");
	}
	return (NULL);
}

void	*monitor(void *arg)
{
	t_data	*data;
	int		i;

	data = arg;
	while (1)
	{
		if (check_eating(data->philos) == 0)
			return (NULL);
		i = -1;
		while (++i < data->nbr_of_philo)
		{
			if (get_time() - data->philos[i].last_eat >= data->time_to_die)
			{
				print_message(data->philos, "is died");
				pthread_mutex_lock(&data->print);
				return (NULL);
			}
		}
	}
}

int	create_philo(t_data *data)
{
	pthread_t	thread_id;
	int			i;

	i = -1;
	while (++i < data->nbr_of_philo)
	{
		data->time = get_time();
		data->philos[i].last_eat = get_time();
		if (pthread_create(&data->philos[i].thread_id, NULL, philo,
				&data->philos[i]))
			return (printf("Error create thread"), 0);
	}
	if (pthread_create(&thread_id, NULL, monitor, data))
		return (printf("Error create thread"), 0);
	if (pthread_join(thread_id, NULL))
		return (printf("Error joining thread"), 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (!ft_parsing(ac, av))
		return (printf("______________Invalid ARGS______________"));
	init_data(&data, ac, av);
	if (!init_philo(&data))
		return (ft_free(&data), 0);
	if (create_philo(&data))
		return (ft_free(&data), 0);
	ft_free(&data);
	printf("ok");
}
