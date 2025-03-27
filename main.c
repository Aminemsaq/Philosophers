#include "philo.h"

long ft_atol(const char *str)
{
    long result = 0;
    int i = 0;

    while (str[i])
    {
        result = (result * 10) + (str[i] - '0');
        i++;
    }
    if (result > INT_MAX)
    {
        printf("ERROR: Value exceeds INT_MAX.\n");
        return -1;
    }
    
    return (int)result;
}

int ft_init(int ac, char **av, t_philo *params)
{
    if (ft_atol(av[1]) == -1)
        return 0;
    params->num_of_philos = ft_atol(av[1]);
    if (ft_atol(av[2]) == -1)
        return 0;
    params->time_to_die = ft_atol(av[2]);
    if (ft_atol(av[3]) == -1)
        return 0; 
    params->time_to_eat = ft_atol(av[3]);
    if (ft_atol(av[4]) == -1)
        return 0; 
    params->time_to_sleep = ft_atol(av[4]);
    if (ac - 1 == 5)
    {
        if (ft_atol(av[5]) == -1)
            return 0; 
        params->num_times_to_eat = ft_atol(av[5]);
    }
	return 1;
}
int ft_parsing(int ac, char **av)
{
	int i = 1;
	int j;

	while(i < ac)
	{
		j = 0;
		while(av[i][j])
		{
			if(av[i][j] < '0' || av[i][j] > '9'){
				printf("ERROR, Not valid");
				return 0;
			}
			j++;
		}
		i++;
	}
	return 1;
}
int	main(int ac, char **av)
{
	t_philo data;

	if(ac - 1 < 4 || ac - 1 > 5){
		printf("ERROR, Not valid input");
		return 0;
	}
	
	if(ft_parsing(ac, av) == 0)
		return 0;
	if(ft_init(ac, av, &data) == 0)
		return 0;
	printf("Ok\n");
}