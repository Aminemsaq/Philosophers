#include "philo.h"



int	main(int ac, char **av)
{
	t_philo philos;
	t_program program;
	pthread_mutex_t *forks;

	if (ac - 1 < 4 || ac - 1 > 5 || ft_parsing(ac, av, &philos) == 0)
	{
		printf("ERROR, Not valid input");
		return (0);
	}
	// init_mutex(&data);
	printf("Ok\n");
}