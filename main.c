#include "philo.h"

int	main(int ac, char **av)
{
	t_philo philos;
	if (ac - 1 < 4 || ac - 1 > 5 || ft_parsing(ac, av) == 0)
	{
		printf("ERROR, Not valid input");
		return (0);
	}
	init_input(&philos, av);
	printf("Ok\n");
}