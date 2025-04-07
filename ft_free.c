#include "philo.h"

void	cleanup(t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->num_philos)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
	}

	pthread_mutex_destroy(&data->print_lock);
	pthread_mutex_destroy(&data->simulation_lock);
	pthread_mutex_destroy(&data->meal_time_lock);

	if (data->philos)
	{
		free(data->philos);
		data->philos = NULL;
	}
}