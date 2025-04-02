#include "philo.h"

void	ft_free(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_of_philo)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->print);
	free(data->philos);
	free(data->forks);
}
