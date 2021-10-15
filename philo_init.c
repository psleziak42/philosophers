#include "philo.h"

int	*ft_init_forks(t_info *info)
{
	int	i;
	int	*widelec;

	i = -1;
	widelec = malloc(sizeof(int) * info->no_of_philo);
	while (++i < info->no_of_philo)
		widelec[i] = 1;
	return (widelec);
}

pthread_mutex_t	*ft_init_philo_mutex(t_info *info)
{
	int				i;
	pthread_mutex_t	*philo_mutex;

	philo_mutex = malloc(sizeof(pthread_mutex_t) * info->no_of_philo);
	i = -1;
	while (++i < info->no_of_philo)
		pthread_mutex_init(&philo_mutex[i], NULL);
	return (philo_mutex);
}

t_philo	*ft_init_philo(t_info *info)
{
	int		i;
	t_philo	*philo;

	philo = malloc(sizeof(t_philo) * info->no_of_philo);
	i = -1;
	while (++i < info->no_of_philo)
	{
		philo[i].id = i + 1;
		philo[i].t_die = info->t_die;
		philo[i].t_eat = info->t_eat;
		philo[i].t_sleep = info->t_sleep;
		philo[i].no_of_meals = info->no_of_meals;
		philo[i].is_dead = &info->is_dead;
		philo[i].is_eating = &info->is_eating;
		philo[i].mutex_left = &info->philo_mutex[i];
		philo[i].mutex_right = &info->philo_mutex[(i + 1) % info->no_of_philo];
		philo[i].mutex_printer = &info->mutex_printer;
		philo[i].mutex_dead = &info->mutex_dead;
		philo[i].fork_left = &info->forks[i];
		philo[i].fork_right = &info->forks[(i + 1) % info->no_of_philo];
		philo[i].state = thinking;
		philo[i].time_start = info->time_start;
		philo[i].time_start_eat = 0;
	}
	return (philo);
}

pthread_t	*ft_init_thread(t_info *info)
{
	int			i;
	pthread_t	*philo_thread;

	philo_thread = malloc(sizeof(pthread_t) * info->no_of_philo);
	i = -1;
	while (++i < info->no_of_philo)
		pthread_create(&philo_thread[i], NULL, &thread_life, &info->philo[i]);
	i = -1;
	while (++i < info->no_of_philo)
		pthread_join(philo_thread[i], NULL);
	return (philo_thread);
}
