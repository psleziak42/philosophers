#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef enum e_philo_state
{
	dead,
	eating,
	sleeping,
	thinking
}				t_philo_state;

typedef struct s_philo
{
	int				id;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	int				no_of_meals;
	t_philo_state	state;
	uint64_t		time_start;
	uint64_t		time_start_eat;
	int				*is_dead;
	int				*is_eating;
	int				*fork_left;
	int				*fork_right;
	pthread_mutex_t	*mutex_printer;
	pthread_mutex_t	*mutex_dead;
	pthread_mutex_t	*mutex_right;
	pthread_mutex_t	*mutex_left;
}				t_philo;

typedef struct s_info
{
	int				no_of_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				no_of_meals;
	int				is_dead;
	int				is_eating;
	int				*forks;
	uint64_t		time_start;
	t_philo			*philo;
	pthread_t		*philo_thread;
	pthread_mutex_t	*philo_mutex;
	pthread_mutex_t	mutex_printer;
	pthread_mutex_t	mutex_dead;
}				t_info;

/* UTILS FUNCTIONS */

int					ft_atoi(const char *nptr);
uint64_t			ft_time(void);

/* INITIALIZATION FUNCTIONS */

int					*ft_init_forks(t_info *info);
pthread_mutex_t		*ft_init_philo_mutex(t_info *info);
t_philo				*ft_init_philo(t_info *info);
pthread_t			*ft_init_thread(t_info *info);

/* THREAD OPERATIONS */

void				ft_printer(t_philo *philo);
int					ft_dead(t_philo *philo, int diff);
int					ft_can_eat(t_philo *philo);
void				*thread_life(void *philo_struct);
int					ft_pick_forks(t_philo *philo);
void				ft_drop_forks(t_philo *philo);
int					ft_time_to_eat_plus_check_dead(t_philo *philo);
int					ft_time_to_sleep_plus_check_dead(t_philo *philo);

#endif
