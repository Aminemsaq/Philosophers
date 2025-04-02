#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				id_next;
	long			last_eat;
	int				count_eat;
	int				num_eat;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	right_fork;
	pthread_t		thread_id;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	long			time;
	int				nbr_of_philo;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				nbr_of_must_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_data;

int					ft_parsing(int ac, char **av);
long				ft_atol(const char *str);
void				init_data(t_data *data, int ac, char **av);
int					init_philo(t_data *data);
long				get_time(void);
void	ft_usleep(long ms);
void	print_message(t_philo *philo, char *str);
void				ft_free(t_data *data);
int	check_eating(t_philo *philo);
#endif