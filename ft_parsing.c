#include "philo.h"

long	ft_atol(const char *str)
{
	long	result;
	int		i;

	result = 0;
	i = 0;
	while (str[i])
	{
		if (result > (LONG_MAX / 10) || (result == (LONG_MAX / 10) && str[i]
				- '0' > LONG_MAX % 10))
		{
			printf("ERROR: Value exceeds LONG_MAX.\n");
			return (-1);
		}
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (result > INT_MAX)
	{
		printf("ERROR: Value exceeds INT_MAX.\n");
		return (-1);
	}
	return (result);
}

int	ft_init(int ac, char **av, t_philo *data)
{
	if (ft_atol(av[1]) == -1)
		return (0);
	data->num_of_philos = ft_atol(av[1]);
	if (ft_atol(av[2]) == -1)
		return (0);
	data->time_to_die = ft_atol(av[2]);
	if (ft_atol(av[3]) == -1)
		return (0);
	data->time_to_eat = ft_atol(av[3]);
	if (ft_atol(av[4]) == -1)
		return (0);
	data->time_to_sleep = ft_atol(av[4]);
	if (ac - 1 == 5)
	{
		if (ft_atol(av[5]) == -1)
			return (0);
		data->num_times_to_eat = ft_atol(av[5]);
	}
	return (1);
}
int	ft_parsing(int ac, char **av, t_philo *data)
{
	int i = 1;
	int j;

	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
			{
				printf("ERROR, Not valid");
				return (0);
			}
			j++;
		}
		i++;
	}
	if (ft_init(ac, av, data) == 0)
		return (0);
	return (1);
}