#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_time
{
	unsigned long long	to_die;
	unsigned long long	to_eat;
	unsigned long long	to_sleep;
	unsigned long long	start;
}				t_time;

typedef struct s_fork
{
	int	left;
	int	right;
}				t_fork;

typedef struct s_params
{
	int					number_of_philosophers;
	int					max_meals;
	pthread_mutex_t		*forks;
	pthread_mutex_t		printer;
	struct s_philo		*philos;
	t_time				time;
}				t_params;

typedef struct s_philo
{
	int					position;
	int					eat_flag;
	unsigned long long	last_eat;
	int					even;
	pthread_mutex_t		*printer;
	t_time				time;
	t_fork				fork;
	t_params			*ptr_to_params;
}				t_philo;

void		init_philo(t_philo	*philo, t_params *params, int i);
size_t		ft_strlen(const char *str);
int			ft_atoi(const char *str);
uint64_t	get_time(uint64_t time);
void		params_init(int ac, char **av, t_params *params);
int			ft_init(int ac, char **av, t_params *params);
void		destroyer(t_params *params);
int			check_params(t_params *params);
void		mutex_print(t_philo *philo, char *message);
int			check_max_meals(t_params *params);
void		eat(t_philo *philo);
void		take_forks(t_philo *philos);
void		put_forks(t_philo *philos);
void		my_usleep(unsigned long long t);

#endif
