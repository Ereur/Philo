#ifndef	PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>

typedef struct s_philo
{
	int 		id;
	pthread_t	philo;
} t_philo;

typedef struct s_tasks
{
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int number_of_eats;
	int nb_of_philos;

}	t_tasks;

typedef struct s_philos
{
	t_philo			philo[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	writing;
	t_tasks			philo_tasks;

} t_philos;

int	ft_atoi(const char *str);
//init phiosophers forks and setup data

#endif
