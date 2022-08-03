/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:42:25 by aamoussa          #+#    #+#             */
/*   Updated: 2022/08/01 14:33:24 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	get_stamp(size_t a, size_t b)
{
	return (b - a);
}

void	print_action(char *message, t_philo *philos)
{
	size_t	time_stamp;

	time_stamp = get_stamp(philos->curent_time, get_time());
	sem_wait((philos->writing));
	printf("%ld %d %s\n", time_stamp, philos->id, message);
	sem_post((philos->writing));
}

void	philo_eats(t_philo *philo)
{
	sem_wait(philo->fork);
	print_action("has taken left_fork", philo);
	// printf("%p\n", philo->right_fork);
	// printf("%p\n", philo->left_fork);
	sem_wait(philo->fork);
	print_action("has taken Righ_fork", philo);
	sem_wait(philo->meal_check);
	philo->last_meal = get_time();
	sem_post(philo->meal_check);
	print_action("is eating", philo);
	philo->count_eats++;
	ft_usleep((philo->time_to_eat));
	sem_post(philo->fork);
	sem_post(philo->fork);
	print_action("is sleeping", philo);
	ft_usleep((philo->time_to_sleep));
}
