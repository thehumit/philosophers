# include "philo.h"

// void	philo_init(t_params *params)
// {
// 	int	i;

// 	i = 0;
// 	while (i < params)
// 	{
// 		/* code */
// 	}

// }
void *printer(void *params)
{
	t_params *params_local;
	params_local = (t_params *)params;
	printf("%d\n", params_local->time.now);
	return(NULL);
}

void	ft_init(int ac, char **av, t_params *params)
{
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
		pthread_create(&id, NULL, &printer, &params);


}
