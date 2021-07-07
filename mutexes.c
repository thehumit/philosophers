#include "philo.h"

void	mutex_print(t_philo *philo, char *message)
{
	pthread_mutex_lock(philo->printer);
	printf("%llu Philo %d %s\n",
		get_time(philo->ptr_to_params->time.start), philo->position, message);
	pthread_mutex_unlock(philo->printer);
}

int	check_max_meals(t_params *params)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < params->number_of_philosophers)
	{
		if (params->philos[i].eat_flag == params->max_meals)
		{
			counter++;
		}
		i++;
	}
	if (counter == params->number_of_philosophers)
		return (1);
	return (0);
}

void	eat(t_philo *philo)
{
	philo->last_eat = get_time(philo->ptr_to_params->time.start);
	my_usleep(philo->ptr_to_params->time.to_eat);
	philo->eat_flag++;
}

void	take_forks(t_philo *philos)
{
	pthread_mutex_lock(&philos->ptr_to_params->forks[philos->fork.left]);
	mutex_print(philos, "took fork");
	pthread_mutex_lock(&philos->ptr_to_params->forks[philos->fork.right]);
	mutex_print(philos, "took fork");
}

void	put_forks(t_philo *philos)
{
	pthread_mutex_unlock(&philos->ptr_to_params->forks[philos->fork.left]);
	pthread_mutex_unlock(&philos->ptr_to_params->forks[philos->fork.right]);
	mutex_print(philos, "is sleeping");
	my_usleep(philos->ptr_to_params->time.to_sleep);
}
