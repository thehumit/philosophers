# ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_params
{
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	int	current_time;
}				t_params;

typedef struct	s_fork
{
	int	l_fork;
	int	r_fork;
}				t_fork;

typedef struct	s_philo
{
	;
}				t_philo;

#endif
