#include "philo.h"

int	init_data(t_data *data, int ac, char **av)
{
	data->num_philos = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	data->num_must_eat = -1;
	if (ac == 6)
		data->num_must_eat = ft_atol(av[5]);
	data->simulation_over = 0;
	data->start_time = get_time_in_ms();//////
	data->forks = NULL;
	data->philos = NULL;
	return (0);
}

int	init_philos(t_data *data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->num_philos);
	if (!data->philos)
		return (1);
	while (i < data->num_philos)
	{
		philo = &data->philos[i];
		philo->id = i + 1;
		philo->meals_eaten = 0;
		philo->last_meal_time = data->start_time;
		philo->left_fork = &data->forks[i];
		philo->right_fork = &data->forks[(i + 1) % data->num_philos];
		philo->data = data;
		i++;
	}
	return (0);
}

int	init_mutexes(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philos);
	if (!data->forks)
		return (1);
	while (i < data->num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (1);
		i++;
	}
	if (pthread_mutex_init(&data->print_lock, NULL) != 0
		|| pthread_mutex_init(&data->simulation_lock, NULL) != 0
		|| pthread_mutex_init(&data->meal_time_lock, NULL) != 0)
		return (1);
	return (0);
}
