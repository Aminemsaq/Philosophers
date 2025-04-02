#include "philo.h"

void	print_forks_table(t_data *data)
{
	printf("\n=== Forks Table ===\n");
	for (int i = 0; i < data->num_of_philos; i++)
	{
		printf("Fork %d - Address: %p\n", data->forks[i].fork_id,
			(void *)&data->forks[i]);
	}
	printf("===================\n");
}

void	print_philos_table(t_data *data)
{
	t_philos	*philo;

	printf("\n=== Philosophers Table ===\n");
	for (int i = 0; i < data->num_of_philos; i++)
	{
		philo = &data->philos[i];
		printf("Philosopher %d:\n", philo->id);
		printf("  Eating: %d\n", philo->eating);
		printf("  Meals Eaten: %d\n", philo->meals_eaten);
		printf("  Left Fork: %p (Fork ID: %d)\n", (void *)philo->first_fork,
			philo->first_fork->fork_id);
		printf("  Right Fork: %p (Fork ID: %d)\n", (void *)philo->second_fork,
			philo->second_fork->fork_id);
	}
	printf("===========================\n");
}

void	init_mutex(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->num_of_philos)
	{
		if (pthread_mutex_init(&data->forks[i].fork, NULL) != 0)
		{
			printf("Error: Mutex initialization failed for fork %d\n", i);
			exit(EXIT_FAILURE);
		}
		data->forks[i].fork_id = i;
	}
}

void	init_philo(t_data *data)
{
	int			i;
	t_philos	*philo;

	i = -1;
	while (++i < data->num_of_philos)
	{
		philo = data->philos + i;
		philo->id = i;
		philo->eating = 0;
		philo->meals_eaten = 0;
		philo->data = data;
		philo->first_fork = &data->forks[philo->id];
		philo->second_fork = &data->forks[(philo->id + 1)
			% philo->data->num_of_philos];
		if (philo->id % 2 == 0)
		{
			philo->second_fork = &data->forks[philo->id];
			philo->first_fork = &data->forks[(philo->id + 1)
				% philo->data->num_of_philos];
		}
	}
}

void	init_input(t_data *data, char **argv)
{
	data->time_to_die = ft_atol(argv[2]);
	data->time_to_eat = ft_atol(argv[3]);
	data->time_to_sleep = ft_atol(argv[4]);
	data->num_of_philos = ft_atol(argv[1]);

	if (argv[5])
		data->num_times_to_eat = ft_atol(argv[5]);
	else
		data->num_times_to_eat = -1;
	data->end_simulation = 0;
	data->philos = malloc(sizeof(t_philos) * data->num_of_philos);
	if (!data->philos)
		exit(EXIT_FAILURE);
	data->forks = malloc(sizeof(t_fork) * data->num_of_philos);
	if (!data->forks)
		exit(EXIT_FAILURE);

	init_mutex(data);
	init_philo(data);
}