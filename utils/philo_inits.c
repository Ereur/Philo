/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:54:50 by aamoussa          #+#    #+#             */
/*   Updated: 2022/06/23 02:56:51 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_forks(t_philos *philos, int id)
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

void	ft_init_mutex(t_philos *philos)
{
	int	i;

	i = 0;
	while (i < philos->nb_of_philos)
	{	
		pthread_mutex_init(&(philos->forks[i]), NULL);
		i++;
	}
	i = 0;
	pthread_mutex_init(&(philos->writing), NULL);
	while (i < philos->nb_of_philos)
		philos->philo[i++]->writing = &philos->writing;
	i = 0;
	while (i < philos->nb_of_philos)
		pthread_mutex_init(&philos->philo[i++]->meal_check, NULL);
}

void	ft_init_philos(t_philos *philos, int ac, char **argv)
{
	int		i;

	philos->nb_of_philos = ft_atoi(argv[1]);
	philos->philo = malloc(sizeof(t_philo *) * (philos->nb_of_philos + 1));
	i = 0;
	while (i < philos->nb_of_philos)
		philos->philo[i++] = malloc(sizeof(t_philo));
	i = 0;
	while (i < philos->nb_of_philos)
	{	
		philos->philo[i]->time_to_die = ft_atoi(argv[2]);
		philos->philo[i]->time_to_eat = ft_atoi(argv[3]);
		philos->philo[i]->time_to_sleep = ft_atoi(argv[4]);
		philos->philo[i]->nb_of_philos = ft_atoi(argv[1]);
		philos->philo[i]->count_eats = 0;
		if (ac == 6)
			philos->philo[i]->number_of_eats = ft_atoi(argv[5]);
		else
			philos->philo[i]->number_of_eats = -1;
		i++;
	}	
	ft_init_mutex(philos);
}
