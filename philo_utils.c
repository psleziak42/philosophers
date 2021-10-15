#include "philo.h"

uint64_t	ft_time(void)
{
	struct timeval	current;

	gettimeofday(&current, NULL);
	return (current.tv_sec * 1000 + current.tv_usec / 1000);
}

int	ft_time_to_eat_plus_check_dead(t_philo *philo)
{
	uint64_t	time_current;

	philo->time_start_eat = ft_time();
	time_current = ft_time();
	while (time_current - philo->time_start_eat < philo->t_eat)
	{
		usleep(10);
		if ((time_current - philo->time_start_eat > philo->t_die))
		{
			ft_dead(philo, 1);
			return (0);
		}
		time_current = ft_time();
	}
	return (1);
}

int	ft_time_to_sleep_plus_check_dead(t_philo *philo)
{
	uint64_t	time_current;
	uint64_t	time_start_sleep;

	time_start_sleep = ft_time();
	time_current = ft_time();
	while (time_current - time_start_sleep < philo->t_sleep)
	{
		usleep(10);
		if ((time_current - philo->time_start_eat > philo->t_die))
		{
			ft_dead(philo, 1);
			return (0);
		}
		time_current = ft_time();
	}
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	z;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '0')
		return (0);
	z = 0;
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		z = z * 10 + nptr[i] - 48;
		i++;
	}
	return (z);
}
