/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:21:09 by aamoussa          #+#    #+#             */
/*   Updated: 2022/07/19 19:01:53 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

// int	check_deth(t_philo *philo)
// {
// 	size_t	time;

// 	time = get_time();
// 	if (get_stamp(philo->last_meal, time) >= philo->time_to_die)
// 	{
// 		print_action("has diead\n", philo);
// 		exit(1);
// 	}
// 	return (1);
// }

int	main(int ac, char **argv)
{
	t_philos	philos;

	ft_init_philos(&philos, ac, argv);
	ft_lunch_philos(&philos);
}
