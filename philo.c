#include "philo.h"

t_info	*ft_parse(int argc, char **argv)
{
	t_info	*info;

	if (argc != 5 && argc != 6)
		return (NULL);
	info = malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->no_of_philo = ft_atoi(argv[1]);
	info->t_die = ft_atoi(argv[2]);
	info->t_eat = ft_atoi(argv[3]);
	info->t_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->no_of_meals = ft_atoi(argv[5]);
	else
		info->no_of_meals = -1;
	info->is_dead = 1;
	info->is_eating = 1;
	info->time_start = ft_time();
	if (info->no_of_philo == 0 || info->t_die == 0 || info->t_eat == 0
		|| info->t_sleep == -1 || info->no_of_meals == 0)
	{
		free(info);
		return (0);
	}
	return (info);
}

void	ft_init(t_info *info)
{
	info->forks = ft_init_forks(info);
	info->philo_mutex = ft_init_philo_mutex(info);
	pthread_mutex_init(&info->mutex_printer, NULL);
	pthread_mutex_init(&info->mutex_dead, NULL);
	info->philo = ft_init_philo(info);
	info->philo_thread = ft_init_thread(info);
}

void	ft_exit(t_info *info)
{
	int	i;

	i = -1;
	free(info->forks);
	free(info->philo);
	free(info->philo_thread);
	while (++i < info->no_of_philo)
		pthread_mutex_destroy(&info->philo_mutex[i]);
	free(info->philo_mutex);
	free(info);
}

int	main(int argc, char **argv)
{
	t_info	*info;

	info = ft_parse(argc, argv);
	if (info == NULL)
	{
		printf("Error: Incorrect input\n");
		return (0);
	}
	if (ft_atoi(argv[1]) == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(ft_atoi(argv[2]) * 1000);
		printf("%d 1 died\n", ft_atoi(argv[2]));
		return (0);
	}
	ft_init(info);
	ft_exit(info);
	return (0);
}
