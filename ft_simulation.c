#include "philo.h"

void print_message(t_philo *philo, const char *message)
{
    long timestamp;
    
    pthread_mutex_lock(&philo->data->simulation_lock);
    if (philo->data->simulation_over)
    {
        pthread_mutex_unlock(&philo->data->simulation_lock);
        return;
    }
    pthread_mutex_unlock(&philo->data->simulation_lock);
    timestamp = get_time_in_ms() - philo->data->start_time;
    pthread_mutex_lock(&philo->data->print_lock);
    printf("%ld %d %s\n", timestamp, philo->id + 1, message);
    pthread_mutex_unlock(&philo->data->print_lock);
}

void    *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (philo->id % 2)
        ft_usleep(100);

    while (1)
    {
        pthread_mutex_lock(&philo->data->simulation_lock);
        if (philo->data->simulation_over)
        {
            pthread_mutex_unlock(&philo->data->simulation_lock);
            break;
        }
        pthread_mutex_unlock(&philo->data->simulation_lock);
        pthread_mutex_lock(philo->right_fork);
        print_message(philo, "has taken a fork");
        pthread_mutex_lock(philo->left_fork);
        print_message(philo, "has taken a fork");
        pthread_mutex_lock(&philo->data->meal_time_lock);
        philo->last_meal_time = get_time_in_ms();
        pthread_mutex_unlock(&philo->data->meal_time_lock);

        print_message(philo, "is eating");
        if (philo->data->num_must_eat > 0)
        {
            pthread_mutex_lock(&philo->data->meal_time_lock);
            philo->meals_eaten++;
            pthread_mutex_unlock(&philo->data->meal_time_lock);
        }
        ft_usleep(philo->data->time_to_eat);
        pthread_mutex_unlock(philo->left_fork);
        pthread_mutex_unlock(philo->right_fork);

        print_message(philo, "is sleeping");
        ft_usleep(philo->data->time_to_sleep);
        print_message(philo, "is thinking");
    }
    return (NULL);
}

void    *monitor(void *arg)
{
    t_data  *data = (t_data *)arg;
    int     i;
    int     all_ate_enough;

    while (1)
    {
        all_ate_enough = 1;
        i = -1;

        while (++i < data->num_philos)
        {
            pthread_mutex_lock(&data->meal_time_lock);
            long time_since_last_meal = get_time_in_ms() - data->philos[i].last_meal_time;
            int meals = data->philos[i].meals_eaten;
            pthread_mutex_unlock(&data->meal_time_lock);
            if (time_since_last_meal >= data->time_to_die)
            {
                pthread_mutex_lock(&data->simulation_lock);
                data->simulation_over = 1;
                pthread_mutex_unlock(&data->simulation_lock);
                pthread_mutex_lock(&data->print_lock);
                printf("%ld %d died\n", get_time_in_ms() - data->start_time, data->philos[i].id);
                pthread_mutex_unlock(&data->print_lock);
                return (NULL);
            }
            if (data->num_must_eat > 0 && meals < data->num_must_eat)
                all_ate_enough = 0;
        }
        if (data->num_must_eat > 0 && all_ate_enough)
        {
            pthread_mutex_lock(&data->simulation_lock);
            data->simulation_over = 1;
            pthread_mutex_unlock(&data->simulation_lock);
            return (NULL);
        }
    }
}

int	start_simulation(t_data *data)
{
	int i;
	pthread_t monitor_thread;

	data->simulation_over = 0;
	data->start_time = get_time_in_ms();
	i = -1;
	while (++i < data->num_philos)
	{
		data->philos[i].last_meal_time = data->start_time;
	}
	if (pthread_create(&monitor_thread, NULL, &monitor, data) != 0)
		return (1);
	i = -1;
	while (++i < data->num_philos)
		if (pthread_create(&data->philos[i].thread, NULL, &routine,
				&data->philos[i]) != 0)
			return (1);
	i = -1;
	while (++i < data->num_philos)
		pthread_join(data->philos[i].thread, NULL);
	pthread_join(monitor_thread, NULL);
	return (0);
}