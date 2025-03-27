#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		num_of_philos;
	int		num_times_to_eat;
}			t_philo;

int			ft_parsing(int ac, char **av, t_philo *data);
#endif