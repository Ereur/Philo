#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	print_action(t_philo *philos)
{
	pthread_mutex_lock(&(philos->writing));
	printf("im philo %d im a live\n", philos->id);
	pthread_mutex_unlock(&(philos->writing));
}

void *routin(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	// printf("%d \n", philo->id);
	print_action(philo);
}

void ft_init_mutex(t_philo *philos)
{
	int	i;

	i =  0;
	while (i < philos->philo_tasks.nb_of_philos)
	{	
		pthread_mutex_init(&(philos->forks[i]), NULL);
		i++;
	}
}

void ft_init_philos(t_philo *philos, int ac, char **argv)
{
	philos->philo_tasks.nb_of_philos = ft_atoi(argv[1]);
	philos->philo_tasks.time_to_die = ft_atoi(argv[2]);
	philos->philo_tasks.time_to_eat = ft_atoi(argv[3]);
	philos->philo_tasks.time_to_sleep = ft_atoi(argv[4]);
	if (ac == 6)
		philos->philo_tasks.number_of_eats = ft_atoi(argv[5]);
	else
		philos->philo_tasks.number_of_eats = -1;
	ft_init_mutex(philos);
	
}



void ft_lunch_philos(t_philo *philos)
{
	int i;

	i = 0;

	while (i < philos->philo_tasks.nb_of_philos)
	{
		philos->id = i;
		
		printf("%d\n", philos->id);
		if (pthread_create(&(philos->philo[i]), NULL, routin, philos))
			continue;	
		i++;
	}
	
}

void ft_wait_philos(t_philo *philos)
{
	int i;
	i = 0;
	while (i < philos->philo_tasks.nb_of_philos)
	{
		pthread_join(philos->philo[i], NULL);
		i++;
	}
}

int main(int ac, char **argv)
{
	t_philo philos;

	ft_init_philos(&philos, ac, argv);
	ft_lunch_philos(&philos);
	ft_wait_philos(&philos);
}