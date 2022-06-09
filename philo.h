#ifndef	PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>


struct s_tasks;

typedef struct s_philo
{
	int 			id;
	pthread_t		philo;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	int 			number_of_eats;
	int				time_to_die;
	int				time_to_eat;
	int 			time_to_sleep;
	int 			nb_of_philos;
	pthread_mutex_t	*writing;
} t_philo;

// typedef struct s_tasks
// {
	
// 	pthread_mutex_t	*writing;

// }	t_tasks;

typedef struct s_philos
{
	t_philo			**philo;
	pthread_mutex_t	forks[200];
	int 			nb_of_philos;
	pthread_mutex_t	writing;

} t_philos;

int	ft_atoi(const char *str);
//init phiosophers forks and setup data

#endif
