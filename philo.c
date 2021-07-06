# include "philo.h"

void eat(t_philo *philo)

void	take_forks(t_philo *philos)
{
	int ret_left;
	int ret_right;
	ret_left = pthread_mutex_lock(&philos->ptr_to_params->forks[philos->fork.left]);
	ret_right = pthread_mutex_lock(&philos->ptr_to_params->forks[philos->fork.right]);
	printf("Took forks: %d\n left: %d\n right: %d\n", philos->position, philos->fork.left, philos->fork.right);
}

void	put_forks(t_philo *philos)
{
	pthread_mutex_unlock(&philos->ptr_to_params->forks[philos->fork.left]);
	pthread_mutex_unlock(&philos->ptr_to_params->forks[philos->fork.right]);
	usleep(philos->ptr_to_params->time.to_sleep * 1000);
}

void	*printer(void *philos)
{
	t_philo *philos_local;
	philos_local = (t_philo *)philos;
	while(1)
	{
		take_forks(philos_local);
		put_forks(philos_local);
	}
	return(NULL);
}

void	init_philo(t_philo	*philo, t_params *params, int i)
{
	philo->position = i;
	philo->eat_flag = 0;
	philo->fork.left = i;
	philo->fork.right = (i + 1) % params->number_of_philosophers;
	philo->ptr_to_params = params;
}

void	ft_init(int ac, char **av, t_params *params)
{
	int i;

	i = 0;
	params->number_of_philosophers = ft_atoi(av[1]);
	params->time.to_die = ft_atoi(av[2]);
	params->time.to_eat = ft_atoi(av[3]);
	params->time.to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		params->max_meals = ft_atoi(av[5]);
	else
		params->max_meals = 0;
	params->time.now = get_time();
	params->philos = malloc(sizeof(t_philo) * params->number_of_philosophers);
	while (i < params->number_of_philosophers)
	{
		init_philo(&params->philos[i], params, i);
		i++;
	}
	params->forks = malloc(sizeof(pthread_mutex_t) * params->number_of_philosophers);
	i = 0;
	while (i < params->number_of_philosophers)
		pthread_mutex_init(&params->forks[i++], NULL);
}

int main(int ac, char **av)
{
	t_params	params;
	int			i;
	pthread_t id;

	i = 0;
	if (ac < 5 || ac > 6)
	{
		printf("Invalid arguments, LOL\n");
		return (-1);
	}
	ft_init(ac, av, &params);
	while (i < params.number_of_philosophers)
	{
		pthread_create(&id, NULL, &printer, &params.philos[i]);
		pthread_detach(id);
		usleep(100);
		i++;
	}

}
