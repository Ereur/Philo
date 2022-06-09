#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include  <sys/time.h>

void	print_action(char *message, t_philo *philos);

size_t	get_stamp(size_t a, size_t b)
{
	return(b - a);
}

size_t get_time()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	check_deth(t_philo *philo)
{
	size_t	time;

	time = get_time();

	printf("%ld \n", get_stamp(philo->last_meal, time));
	if (get_stamp(philo->last_meal, time) >= philo->time_to_die)
	{
		print_action("has diead\n", philo);
		exit(1);
	}
	return(1);
}

void init_forks(t_philos *philos,int id)
{
	if (id == philos->nb_of_philos)
	{	
		philos->philo[id - 1]->left_fork = &philos->forks[id - 1];
		philos->philo[id - 1]->right_fork = &philos->forks[0];
	}
	else 
	{
		philos->philo[id - 1]->left_fork = &philos->forks[id - 1];
		philos->philo[id - 1]->right_fork = &philos->forks[id];
	}
	

	
}
void	print_action(char *message, t_philo *philos)
{
	size_t	time_stamp;

	time_stamp = get_stamp(philos->curent_time, get_time());
	pthread_mutex_lock((philos->writing));
	printf("%ld %d %s\n", time_stamp, philos->id, message);
	pthread_mutex_unlock((philos->writing));
}

void	philo_eats(t_philo *philo, int i)
{
	if (i)
	{	
		pthread_mutex_lock(philo->left_fork);
		print_action("has taken left_fork",philo);
		pthread_mutex_lock(philo->right_fork);
		print_action("has taken Righ_fork",philo);
		philo->last_meal = get_time();
		print_action("is eating",philo);
		usleep(philo->time_to_eat * 1000);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		print_action("is sleeping",philo);
		usleep(philo->time_to_sleep * 1000);
	}
	else 
	{
		pthread_mutex_lock(philo->right_fork);
		print_action("has taken Righ_fork",philo);
		pthread_mutex_lock(philo->left_fork);
		print_action("has taken left_fork",philo);
		philo->last_meal = get_time();
		print_action("is eating",philo);
		usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		print_action("is sleeping",philo);
		usleep(philo->time_to_sleep);
	}
}


void *routin(void *philos)
{
	t_philo	*philo = (t_philo *)philos;
	while (check_deth(philo))
	{
		// pthread_mutex_lock(philo->writing);		philo->last_meal = get_time();

		if (philo->nb_of_philos == philo->id)
		{
			philo_eats(philo, 0);
			print_action("Is thinking",philo);
		}
		else
		{
			philo_eats(philo, 1);
			print_action("Is thinking",philo);
		}
		// pthread_mutex_unlock(philo->writing);
	}
	return	(NULL);
}

void ft_init_mutex(t_philos *philos)
{
	int	i;

	i =  0;
	while (i < philos->nb_of_philos)
	{	
		pthread_mutex_init(&(philos->forks[i]), NULL);
		i++;
	}
	i = 0;
	pthread_mutex_init(&(philos->writing), NULL);
	while (i < philos->nb_of_philos)
		philos->philo[i++]->writing = &philos->writing;
	
}

void ft_init_philos(t_philos *philos, int ac, char **argv)
{
	int		i;

	philos->nb_of_philos = ft_atoi(argv[1]);
	philos->philo = malloc(sizeof(t_philo *) * (philos->nb_of_philos + 1));
	i = 0;
	while(i < philos->nb_of_philos)
		philos->philo[i++] = malloc(sizeof(t_philo));
	i = 0;
	while (i < philos->nb_of_philos)
	{	
		philos->philo[i]->time_to_die = ft_atoi(argv[2]);
		philos->philo[i]->time_to_eat = ft_atoi(argv[3]);
		philos->philo[i]->time_to_sleep = ft_atoi(argv[4]);
		philos->philo[i]->nb_of_philos= ft_atoi(argv[1]);
		if (ac == 6)
			philos->philo[i]->number_of_eats = ft_atoi(argv[5]);
		else 
			philos->philo[i]->number_of_eats = -1;
		i++;
	}
	ft_init_mutex(philos);
}

void ft_lunch_philos(t_philos *philos)
{
	size_t time;
	int		i;

	time = get_time();
	i = 0;
	while (i < philos->nb_of_philos)
	{
		philos->philo[i]->curent_time = time;
		philos->philo[i]->last_meal = time;
		philos->philo[i]->id = i + 1;
		init_forks(philos, philos->philo[i]->id);
		pthread_create(&(philos->philo[i]->philo), NULL, routin, (philos->philo[i]));
		i++;
		// usleep(1000);
	}
	
}

void ft_wait_philos(t_philos *philos)
{
	int i;
	i = 0;
	while (i < philos->nb_of_philos)
	{
		pthread_join(philos->philo[i]->philo, NULL);
		i++;
	}
}

int main(int ac, char **argv)
{
	t_philos philos;

	ft_init_philos(&philos, ac, argv);
	ft_lunch_philos(&philos);
	ft_wait_philos(&philos);
}