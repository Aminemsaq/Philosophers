#include "philo.h"

int	ft_check_overflow(int ac, char **av, t_philo *data)
{
	if (ft_atol(av[1]) == -1)
		return (0);
	if (ft_atol(av[2]) == -1)
		return (0);
	if (ft_atol(av[3]) == -1)
		return (0);
	if (ft_atol(av[4]) == -1)
		return (0);
	if (ac - 1 == 5)
	{
		if (ft_atol(av[5]) == -1)
			return (0);
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
	if (ft_check_overflow(ac, av, data) == 0)
		return (0);

	return (1);
}