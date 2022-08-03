/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_lunch.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 22:02:43 by aamoussa          #+#    #+#             */
/*   Updated: 2022/07/30 02:33:38 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routin(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	while (1)
	{
		if (philo->id % 2 == 0)
			usleep(50);
		philo_eats(philo);
		print_action("Is thinking", philo);
	}
	return (NULL);
}

int	check_philos_life(t_philos *philos, int i, int time)
{
	size_t	time_stamp;

	if (get_stamp(philos->philo[i]->last_meal, time)
		>= philos->philo[i]->time_to_die)
	{	
		time_stamp = get_stamp(philos->philo[i]->curent_time,
				get_time());
		pthread_mutex_lock((philos->philo[i]->writing));
		printf("%ld %d died\n", time_stamp, philos->philo[i]->id);
		return (1);
	}
	return (0);
}

int	check_eats(t_philos *philos)
{
	int	i;
	int	eats;

	eats = philos->philo[0]->number_of_eats;
	i = 0;
	while (i < philos->nb_of_philos)
	{
		if (philos->philo[i]->count_eats < eats)
			return (1);
		i++;
	}
	return (0);
}

void	check(t_philos *philos)
{
	int		i;
	int		time;

	i = 0;
	while (1)
	{
		while (i < philos->nb_of_philos)
		{
			time = get_time();
			pthread_mutex_lock(&philos->philo[i]->meal_check);
			if (philos->philo[i]->number_of_eats != -1)
				if (!(check_eats(philos)))
					return ;
			if (check_philos_life(philos, i, time))
				return ;
			pthread_mutex_unlock(&philos->philo[i]->meal_check);
			i++;
		}
		i = 0;
	}
}

void	ft_lunch_philos(t_philos *philos)
{
	size_t	time;
	int		i;

	time = get_time();
	i = 0;
	while (i < philos->nb_of_philos)
	{
		philos->philo[i]->curent_time = time;
		philos->philo[i]->last_meal = time;
		philos->philo[i]->id = i + 1;
		init_forks(philos, philos->philo[i]->id);
		pthread_create(&(philos->philo[i]->philo), NULL, routin,
			(philos->philo[i]));
		i++;
	}
	check(philos);
}
