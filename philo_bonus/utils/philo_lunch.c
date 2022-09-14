/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lunch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:02:43 by aamoussa          #+#    #+#             */
/*   Updated: 2022/08/23 13:00:49 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	check_philo_life(t_philo *philo, int time)
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
