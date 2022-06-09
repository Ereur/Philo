#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void init_forks(t_philos *philos,int id)
{
	philos->philo[id - 1]->left_fork = &philos->forks[id - 1];
	
}
void	print_action(t_philo *philos)
{
	// pthread_mutex_lock(&(philos->writing));
	printf("im philo %d im a live\n", philos->id);
	// printf("time to die %d\n",philos->tasks->time_to_die);
	// pthread_mutex_unlock(&(philos->writing));
}

void *routin(void *philos)
{
	t_philo	*philo = (t_philo *)philos;
	pthread_mutex_lock(philo->writing);
	print_action(philos);
	printf("my left fork is : %p\n",philo->left_fork);
	printf("my right fork is %p\n",philo->right_fork);
	// printf("time to sleep %d\n",philo->time_to_sleep);
	// printf("nb of philo %d\n",philo->nb_of_philos);
	// printf("nb of eats %d\n",philo->number_of_eats);
	printf("\n");
	pthread_mutex_unlock(philo->writing);
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
	// i = 0;
	// while (i < philos->nb_of_philos)
	// {
	// 	philos->philo[i]->left_fork = &philos->forks[i];
	// 	philos->philo[i]->right_fork = &philos->forks[i + 1];
	// }
	
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
	// t_philo *philo;

	// philo = philos->philo[0];
	int i;

	i = 0;

	while (i < philos->nb_of_philos)
	{
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
	
	while (1)
		;
	ft_init_philos(&philos, ac, argv);
	ft_lunch_philos(&philos);
	ft_wait_philos(&philos);
}