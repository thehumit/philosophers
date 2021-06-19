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
	t_philo	*philos;
	t_time	time_params;

}				t_params;


typedef struct	s_time
{
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	current_time;
}				t_time;

typedef struct	s_fork
{
	int	l_fork;
	int	r_fork;
}				t_fork;

typedef struct	s_philo
{
	int eat_flag;
	int	max_meals;
	
}				t_philo;


/////////////////////////////////////////////

typedef struct		s_philo
{
	int				position;
	int				is_eating;
	uint64_t		limit;
	uint64_t		last_eat;
	int				lfork;
	int				rfork;
	int				eat_count;
	struct s_state	*state;
	pthread_mutex_t	mutex;
	pthread_mutex_t	eat_m;
}					t_philo;

typedef struct		s_state
{
	int				amount;
	uint64_t		time_to_die;
	uint64_t		time_to_eat;
	uint64_t		time_to_sleep;
	int				must_eat_count;

	uint64_t		start;

	t_philo			*philos;
	pthread_mutex_t	*forks_m;
	pthread_mutex_t	write_m;
	pthread_mutex_t	somebody_dead_m;
}					t_state;

#endif
