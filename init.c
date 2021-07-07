#include "philo.h"

void	init_philo(t_philo	*philo, t_params *params, int i)
{
	philo->position = i;
	philo->eat_flag = 0;
	philo->fork.left = i;
	philo->fork.right = (i + 1) % params->number_of_philosophers;
	philo->ptr_to_params = params;
	philo->printer = &(params->printer);
	philo->last_eat = 0;
	philo->even = philo->position % 2 + 1;
}

void	params_init(int ac, char **av, t_params *params)
{
	params->number_of_philosophers = ft_atoi(av[1]);
	params->time.to_die = ft_atoi(av[2]);
	params->time.to_eat = ft_atoi(av[3]);
	params->time.to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		params->max_meals = ft_atoi(av[5]);
	else
		params->max_meals = 0;
}

int	ft_init(int ac, char **av, t_params *params)
{
	int	i;

	i = 0;
	params_init(ac, av, params);
	params->philos = malloc(sizeof(t_philo) * params->number_of_philosophers);
	if (params->philos == NULL)
		return (0);
	pthread_mutex_init(&params->printer, NULL);
	while (i < params->number_of_philosophers)
	{
		init_philo(&params->philos[i], params, i);
		i++;
	}
	params->forks = malloc(sizeof(pthread_mutex_t)
			* params->number_of_philosophers);
	if (params->forks == NULL)
		return (0);
	i = 0;
	while (i < params->number_of_philosophers)
		pthread_mutex_init(&params->forks[i++], NULL);
	return (1);
}

void	destroyer(t_params *params)
{
	int	tmp;
	int	i;

	tmp = params->number_of_philosophers;
	i = 0;
	pthread_mutex_destroy(&params->printer);
	while (i < tmp)
	{
		pthread_mutex_destroy(&params->forks[i]);
		i++;
	}
	free(params->forks);
	free(params->philos);
}

int	check_params(t_params *params)
{
	if (params->number_of_philosophers == 0)
	{
		destroyer(params);
		return (1);
	}
	return (0);
}
