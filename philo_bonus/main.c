/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:42:50 by aamoussa          #+#    #+#             */
/*   Updated: 2022/08/23 13:56:02 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

#include "./philo_bonus.h"

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

pid_t	my_fork(void)
{
	pid_t	i;

	i = fork();
	if (i < 0)
	{
		perror("error");
		exit(1);
	}
	return (i);
}

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

void	ft_childs(t_philo *philo)
{
	int	time;

	sem_unlink("count");
	philo->count = sem_open("count", O_CREAT, 0644, 1);
	pthread_create(&(philo->philo), NULL, routin, philo);
	while (42)
	{
		time = get_time();
		sem_wait(philo->meal_check);
		if (philo->number_of_eats != -1)
		{	
			if (!(check_eats(philo)))
			{
				sem_post(philo->meal_check);
				exit(EXIT_SUCCESS);
			}
		}
		if (check_philo_life(philo, time))
		{
			exit(EXIT_FAILURE);
		}
		sem_post(philo->meal_check);
	}
	return ;
}

int	main(int ac, char **argv)
{
	t_philos	philos;
	int			i;
	pid_t		process;
	size_t		time;

	i = 0;
	time = get_time();
	ft_init_philos(&philos, ac, argv);
	while (i < philos.nb_of_philos)
	{
		philos.philo[i]->curent_time = time;
		philos.philo[i]->last_meal = time;
		philos.philo[i]->id = i + 1;
		process = my_fork();
		if (process != 0)
			philos.process_id[i] = process;
		if (process == 0)
		{
			ft_childs(philos.philo[i]);
			return (0);
		}		
		i++;
	}
	ft_wait(philos);
}
