# include "philo.h"

ft_init(int ac, char **av, t_params *params)
{
	params->number_of_philosophers = ft_atoi(av[0]);
	params->time_to_die = ft_atoi(av[1]);
	params->time_to_eat = ft_atoi(av[2]);
	params->time_to_sleep = ft_atoi(av[3]);
	if (ac == 6)
		params->number_of_times_each_philosopher_must_eat = ft_atoi(av[4]);
	else
		params->number_of_times_each_philosopher_must_eat = NULL;
	params->current_time = get_time();
}

int main(int ac, char **av)
{
	t_params	params;
	int			i;
	pthread_t id;

	if (ac < 5 || ac > 6)
	{
		printf("Invalid arguments, LOL\n");
		return (-1);
	}
	ft_init(ac, av, &params);
	while (i < params.number_of_philosophers)
		pthread_create(id, );


}
