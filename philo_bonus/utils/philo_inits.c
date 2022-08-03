/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_inits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 21:54:50 by aamoussa          #+#    #+#             */
/*   Updated: 2022/08/01 14:35:47 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

// void	init_forks(t_philos *philos, int id)
// {
// 	if (id == philos->nb_of_philos)
// 	{	
// 		philos->philo[id - 1]->left_fork = philos->forks[id - 1];
// 		philos->philo[id - 1]->right_fork = philos->forks[0];
// 	}
// 	else
// 	{
// 		philos->philo[id - 1]->left_fork = philos->forks[id - 1];
// 		philos->philo[id - 1]->right_fork = philos->forks[id];
// 	}
// }

void	ft_init_semaphore(t_philos *philos)
{
	int	i;

	i = 0;
	sem_unlink("/fokrs");
	philos->forks = sem_open("/forks", O_CREAT, 0644, philos->nb_of_philos);
	// printf("%p\n", philos->forks);
	sem_unlink("writing");
	philos->writing = sem_open("writing", O_CREAT, 0644, 1);
	i = 0;
	sem_unlink("mealcheck");
	philos->philo[0]->meal_check = sem_open("mealcheck", O_CREAT, 0644, 1);
	while (i < philos->nb_of_philos)
	{
		philos->philo[i]->fork = philos->forks;
		philos->philo[i]->writing = philos->writing;
		philos->philo[i]->meal_check = philos->philo[0]->meal_check;
		i++;
	}
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
	ft_init_semaphore(philos);
}
