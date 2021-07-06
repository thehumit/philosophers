# ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_time
{
	int	to_die;
	int	to_eat;
	int	to_sleep;
	int	now;
}				t_time;

typedef struct	s_fork
{
	int	left;
	int	right;
}				t_fork;

typedef struct	s_params
{
	int	number_of_philosophers;
	int	max_meals;
	pthread_mutex_t *forks;
	struct s_philo	*philos;
	t_time	time;
}				t_params;

typedef struct	s_philo
{
	int		position;
	int		eat_flag;
	t_time	time;
	t_fork	fork;
	t_params	*ptr_to_params;
}				t_philo;



/////////////////////////////////////////////

// typedef struct		s_philo
// {
// 	int				position;
// 	int				is_eating;
// 	uint64_t		limit;
// 	uint64_t		last_eat;
// 	int				lfork;
// 	int				rfork;
// 	int				eat_count;
// 	struct s_state	*state;
// 	pthread_mutex_t	mutex;
// 	pthread_mutex_t	eat_m;
// }					t_philo;

// typedef struct		s_state
// {
// 	int				amount;
// 	uint64_t		time_to_die;
// 	uint64_t		time_to_eat;
// 	uint64_t		time_to_sleep;
// 	int				must_eat_count;

// 	uint64_t		start;

// 	t_philo			*philos;
// 	pthread_mutex_t	*forks_m;
// 	pthread_mutex_t	write_m;
// 	pthread_mutex_t	somebody_dead_m;
// }					t_state;

size_t	ft_strlen(const char *str);
int	ft_atoi(const char *str);
uint64_t	get_time(void);

#endif
