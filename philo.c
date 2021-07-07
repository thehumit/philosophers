#include "philo.h"

void	*printer(void *philo)
{
	t_philo	*philo_local;

	philo_local = (t_philo *)philo;
	if (philo_local->even == 1)
		my_usleep(philo_local->ptr_to_params->time.to_eat);
	while (1)
	{
		take_forks(philo_local);
		eat(philo_local);
		put_forks(philo_local);
	}
	return (NULL);
}

int	monitor(t_params *params)
{
	int	i;

	while (21)
	{
		i = -1;
		while (++i < params->number_of_philosophers)
		{
			if (params->time.to_die
				< get_time(params->time.start) - params->philos[i].last_eat)
			{
				pthread_mutex_lock(&params->printer);
				printf("%llu Philosopher %d is dead\n",
					get_time(params->time.start), params->philos[i].position);
				destroyer(params);
				return (0);
			}
			if (params->max_meals != 0 && check_max_meals(params))
			{
				pthread_mutex_lock(&params->printer);
				printf("Everybody finished their meal\n");
				destroyer(params);
				return (0);
			}
		}
	}
}

int	main(int ac, char **av)
{
	t_params	params;
	int			i;
	pthread_t	id;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		printf("Invalid arguments, LOL\n");
		return (-1);
	}
	ft_init(ac, av, &params);
	if (check_params(&params))
		return (0);
	params.time.start = get_time(0);
	while (i < params.number_of_philosophers)
	{
		pthread_create(&id, NULL, &printer, &params.philos[i]);
		pthread_detach(id);
		i++;
	}
	if (!monitor(&params))
		return (0);
}
