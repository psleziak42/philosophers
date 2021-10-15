#include "philo.h"
int	ft_pick_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_left);
	pthread_mutex_lock(philo->mutex_right);
	if ((*philo->fork_left) && (*philo->fork_right))
	{
		(*philo->fork_left) = 0;
		(*philo->fork_right) = 0;
		pthread_mutex_unlock(philo->mutex_left);
		pthread_mutex_unlock(philo->mutex_right);
	}
	else
	{
		pthread_mutex_unlock(philo->mutex_left);
		pthread_mutex_unlock(philo->mutex_right);
		return (0);
	}
	return (1);
}

void	ft_drop_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->mutex_right);
	pthread_mutex_lock(philo->mutex_left);
	(*philo->fork_left) = 1;
	(*philo->fork_right) = 1;
	pthread_mutex_unlock(philo->mutex_right);
	pthread_mutex_unlock(philo->mutex_left);
}
