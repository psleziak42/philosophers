#include "philo.h"

void	ft_printer(t_philo *philo)
{
	uint64_t	t_diff;
	uint64_t	time_current;

	time_current = ft_time();
	pthread_mutex_lock(philo->mutex_printer);
	t_diff = time_current - philo->time_start;
	if (philo->state == dead)
		printf("%llu %d died\n", t_diff, philo->id);
	else if (philo->state == eating)
	{
		printf("%llu %d has taken a fork\n", t_diff, philo->id);
		printf("%llu %d has taken a fork\n", t_diff, philo->id);
		printf("%llu %d is eating\n", t_diff, philo->id);
	}
	else if (philo->state == sleeping)
		printf("%llu %d is sleeping\n", t_diff, philo->id);
	else if (philo->state == thinking)
		printf("%llu %d is thinking\n", t_diff, philo->id);
	pthread_mutex_unlock(philo->mutex_printer);
}

int	ft_dead(t_philo *philo, int diff)
{
	uint64_t	time_current;

	pthread_mutex_lock(philo->mutex_dead);
	if (*philo->is_dead == 0)
	{
		pthread_mutex_unlock(philo->mutex_dead);
		return (0);
	}
	time_current = ft_time();
	if (diff == 1 || (philo->t_die < (time_current - philo->time_start_eat)
			&& (philo->time_start_eat != 0)))
	{
		philo->state = dead;
		*philo->is_dead = 0;
		pthread_mutex_unlock(philo->mutex_dead);
		ft_printer(philo);
		return (0);
	}
	else
		pthread_mutex_unlock(philo->mutex_dead);
	return (1);
}

int	ft_can_eat(t_philo *philo)
{
	if (!ft_pick_forks(philo))
		return (0);
	else
	{
		ft_printer(philo);
		if (!ft_time_to_eat_plus_check_dead(philo))
			return (0);
		philo->no_of_meals--;
		philo->state = sleeping;
		ft_drop_forks(philo);
	}
	return (1);
}

void	*thread_life(void *philo_struct)
{
	t_philo	*philo;

	philo = (t_philo *)philo_struct;
	while (ft_dead(philo, 0) && philo->no_of_meals != 0)
	{
		if (philo->state == eating)
		{
			if (!ft_can_eat(philo))
				continue ;
		}
		else if (philo->state == sleeping)
		{
			ft_printer(philo);
			if (!ft_time_to_sleep_plus_check_dead(philo))
				break ;
			philo->state = thinking;
		}
		else if (philo->state == thinking)
		{
			if (philo->time_start_eat != 0)
				ft_printer(philo);
			philo->state = eating;
		}
	}
	return (NULL);
}
