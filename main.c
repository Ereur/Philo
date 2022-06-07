#include "philo.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	print_action(t_philo *philos)
{
	// pthread_mutex_lock(&(philos->writing));
	printf("im philo %d im a live\n", philos->id);
	// printf("time to die %d\n",philos->tasks->time_to_die);
	// pthread_mutex_unlock(&(philos->writing));
}

void *routin(t_philo *philos)
{
	// t_philo	*philo = (t_philo *)philos;
	// printf("%d \n", philo->id);
	// printf("hello\n");
	printf("time to die %d\n",philos->tasks->time_to_die);
	print_action(philos);
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
}

void ft_init_philos(t_philos *philos, int ac, char **argv)
{
	int		i;
	t_tasks	rules;
	i = 0;
	rules.nb_of_philos = ft_atoi(argv[1]);
	philos->nb_of_philos = rules.nb_of_philos;
	rules.time_to_die = ft_atoi(argv[2]);
	rules.time_to_eat = ft_atoi(argv[3]);
	rules.time_to_sleep = ft_atoi(argv[4]);
	if (ac == 6)
		rules.number_of_eats = ft_atoi(argv[5]);
	else
		rules.number_of_eats = -1;
	philos->philo = malloc(sizeof(t_philo *) * (rules.nb_of_philos + 1));
	i = 0;
	while(i < rules.nb_of_philos)
		philos->philo[i++] = malloc(sizeof(t_philo));
	i = 0;
	while (i < rules.nb_of_philos)
		philos->philo[i++]->tasks = &rules;
	
	// i = 0;
	// while (i < rules.nb_of_philos)
	// {
	// 	printf("%d\n", philos->philo[i++].tasks->time_to_die);
	// }
	// exit(1);
	ft_init_mutex(philos);
}

void ft_lunch_philos(t_philos *philos)
{
	t_philo *philo;

	philo = philos->philo[0];
	int i;

	i = 0;

	while (i < philos->nb_of_philos)
	{
		philos->philo[i]->id = i + 1;
		// printf("%d\n", philos->philo[i]->id);
		routin(philo);
		// pthread_create(&(philos->philo[i]->philo), NULL, routin, &(philos->philo[i]));
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
	// int i = 0;
	// while (i < philos.nb_of_philos)
	// {
	// 	printf("%d\n", philos.philo[i++].tasks->time_to_die);
	// }
	ft_lunch_philos(&philos);
	ft_wait_philos(&philos);
}