#ifndef	PHILO_H
# define PHILO_H

# include <pthread.h>
# include <limits.h>
typedef struct s_tasks
{
	int	time_to_die;
	int	time_to_eat;
	int time_to_sleep;
	int number_of_eats;
	int nb_of_philos;

}	t_tasks;

typedef struct s_philop
{
	int				id;
	pthread_t		philo[200];
	pthread_mutex_t	forks[200];
	pthread_mutex_t	writing;
	t_tasks			philo_tasks;

} t_philo;

int	ft_atoi(const char *str);
//init phiosophers forks and setup data
void ft_init_philos(t_philo *philos, int ac, char **argv);
#endif
