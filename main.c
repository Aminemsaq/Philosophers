#include "philo.h"

void clean_data(t_data *data)
{
    int i = 0;

    if (!data)
        return;
    while (i < data->num_of_philos)
    {
        pthread_mutex_destroy(&data->forks[i].fork);
        i++;
    }
    free(data->forks);
    free(data->philos);
}

int main(int ac, char **av)
{
	t_data data;
	if (ac - 1 < 4 || ac - 1 > 5 || ft_parsing(ac, av) == 0)
	{
		printf("ERROR, Not valid input\n");
		return (1);
	}
	init_input(&data, av);
	
	clean_data(&data);
	printf("Ok\n");

	return (0);
}
