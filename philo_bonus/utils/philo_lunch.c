/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lunch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:02:43 by aamoussa          #+#    #+#             */
/*   Updated: 2022/08/01 11:41:51 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	check_philo_life(t_philo *philo, int i, int time)
{
	size_t	time_stamp;

	if (get_stamp(philo->last_meal, time)
		>= philo->time_to_die)
	{	
		time_stamp = get_stamp(philo->curent_time,
				get_time());
		sem_wait((philo->writing));
		printf("%ld %d died\n", time_stamp, philo->id);
		return (1);
	}
	return (0);
}

int	check_eats(t_philo *philo)
{
	int	eats;

	eats = philo->number_of_eats;
	if (philo->count_eats < eats)
		return (1);
	return (0);
}

// void	check(t_philos *philos)
// {
// 	int		i;
// 	int		time;

// 	i = 0;
// 	while (1)
// 	{
// 		while (i < philos->nb_of_philos)
// 		{
// 			time = get_time();
// 			pthread_mutex_lock(&philos->philo[i]->meal_check);
// 			if (philos->philo[i]->number_of_eats != -1)
// 				if (!(check_eats(philos)))
// 					return ;
// 			if (check_philos_life(philos, i, time))
// 				return ;
// 			pthread_mutex_unlock(&philos->philo[i]->meal_check);
// 			i++;
// 		}
// 		i = 0;
// 	}
// }

// void	ft_lunch_philos(t_philos *philos)
// {
// 	size_t	time;
// 	int		i;

// 	time = get_time();
// 	i = 0;
// 	while (i < philos->nb_of_philos)
// 	{
// 		philos->philo[i]->curent_time = time;
// 		philos->philo[i]->last_meal = time;
// 		philos->philo[i]->id = i + 1;
// 		init_forks(philos, philos->philo[i]->id);
// 		pthread_create(&(philos->philo[i]->philo), NULL, routin,
// 			(philos->philo[i]));
// 		i++;
// 	}
// 	check(philos);
// }
