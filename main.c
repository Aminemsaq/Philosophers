#include "philo.h"

int	main(int ac, char **av)
{
	t_philo data;

	if (ac - 1 < 4 || ac - 1 > 5)
	{
		printf("ERROR, Not valid input");
		return (0);
	}
	if (ft_parsing(ac, av, &data) == 0)
		return (0);
	printf("Ok\n");
}