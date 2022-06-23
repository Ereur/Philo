/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:42:25 by aamoussa          #+#    #+#             */
/*   Updated: 2022/06/23 01:29:56 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	get_stamp(size_t a, size_t b)
{
	return (b - a);
}

void	print_action(char *message, t_philo *philos)
{
	size_t	time_stamp;

	time_stamp = get_stamp(philos->curent_time, get_time());
	pthread_mutex_lock((philos->writing));
	printf("%ld %d %s\n", time_stamp, philos->id, message);
	pthread_mutex_unlock((philos->writing));
}

void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_action("has taken left_fork", philo);
	pthread_mutex_lock(philo->right_fork);
	print_action("has taken Righ_fork", philo);
	pthread_mutex_lock(&philo->meal_check);
	philo->last_meal = get_time();
	pthread_mutex_unlock(&philo->meal_check);
	print_action("is eating", philo);
	philo->count_eats++;
	ft_usleep((philo->time_to_eat));
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	print_action("is sleeping", philo);
	ft_usleep((philo->time_to_sleep));
}
