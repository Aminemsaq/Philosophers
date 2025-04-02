#include "philo.h"

void	init_data(t_data *data, int ac, char **av)
{
    data->nbr_of_philo = ft_atol(av[1]);
	data->time_to_die = ft_atol(av[2]);
	data->time_to_eat = ft_atol(av[3]);
	data->time_to_sleep = ft_atol(av[4]);
	data->nbr_of_must_eat = -1;
	if (ac == 6)
		data->nbr_of_must_eat = ft_atol(av[5]);
}
void	init_info_philo(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->nbr_of_philo)
	{
		data->philos[i].data = data;
		if (data->nbr_of_must_eat > 0)
		{
			data->philos[i].num_eat = data->nbr_of_must_eat;
			data->philos[i].count_eat = 0;
		}
		data->philos[i].id = i;
		if (i + 1 >= data->nbr_of_philo)
			data->philos[i].id_next = 0;
		else
			data->philos[i].id_next = i + 1;
	}
}
int	init_philo(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(t_data) * data->nbr_of_philo);
	data->philos = malloc(sizeof(t_philo) * data->nbr_of_philo);
	if (!data->forks || !data->philos)
		return (printf("Error of malloc"), 0);
	i = -1;
	while (++i < data->nbr_of_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (printf("Error of mutex"), 0);
	}
	if (pthread_mutex_init(&data->print, NULL))
		return (printf("Error of mutex"), 0);
	init_info_philo(data);
	return (1);
}