#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

typedef struct s_fork
{
	pthread_mutex_t fork;
	int				fork_id;
}					t_fork;

typedef struct s_philos t_philos;

typedef struct s_data
{
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_of_philos;
	int				num_times_to_eat;
	size_t			start_simulation;
	int 			end_simulation;
	t_fork			*forks;
	t_philos		*philos;
}					t_data;

struct s_philos
{
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	t_fork			*first_fork;
	t_fork  		*second_fork;
	pthread_t 		thread_id;
	t_data 			*data;
};


// Function Prototypes
int					ft_parsing(int ac, char **av);
long				ft_atol(const char *str);
void				init_input(t_data *data, char **argv);

#endif
