/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amsaq <amsaq@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 19:13:03 by amsaq             #+#    #+#             */
/*   Updated: 2025/04/07 18:09:21 by amsaq            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	pthread_t			thread;
	int					id;
	int					meals_eaten;
	long				last_meal_time;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	t_data				*data;
}						t_philo;

typedef struct s_data
{
	int					num_philos;
	int					num_must_eat;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				start_time;
	int					simulation_over;
	pthread_mutex_t		simulation_lock;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		meal_time_lock;
	pthread_mutex_t		*forks;
	t_philo				*philos;
}						t_data;

int						ft_parsing(int ac, char **av);
long					ft_atol(const char *str);
int						init_data(t_data *data, int ac, char **av);
int						init_mutexes(t_data *data);
int						init_philos(t_data *data);
int						start_simulation(t_data *data);
int						ft_usleep(size_t milliseconds);
long					get_time_in_ms(void);
void					cleanup(t_data *data);
#endif