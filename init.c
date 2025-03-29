#include "philo.h"

void	init_input(t_philo *philo, char **argv)
{
	philo->time_to_die = ft_atol(argv[2]);
	philo->time_to_eat = ft_atol(argv[3]);
	philo->time_to_sleep = ft_atol(argv[4]);
	philo->num_of_philos = ft_atol(argv[1]);
	if (argv[5])
		philo->num_times_to_eat = ft_atol(argv[5]);
	else
		philo->num_times_to_eat = -1;
}

