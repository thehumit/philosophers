#include "philo.h"

uint64_t	get_time(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * (uint64_t)1000) + (tv.tv_usec / 1000));
}

int	ft_atoi(const char *str)
{
	int		sign;
	int		nbr;

	sign = 1;
	nbr = 0;
	while ((*str == 32) || ((*str >= 9) && (*str <= 13)))
		str++;
	if ((*str == '+') || (*str == '-'))
	{
		if (*str == '-')
			sign = -1;
		else
			sign = 1;
		str++;
	}
	while (((int)*str >= 48) && (int)*str <= 57)
	{
		nbr = nbr * 10 + ((int)*str - 48);
		str++;
	}
	return (nbr * sign);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (*str++ != '\0')
		i++;
	return (i);
}

