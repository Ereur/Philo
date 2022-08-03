/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:42:50 by aamoussa          #+#    #+#             */
/*   Updated: 2022/08/01 14:36:21 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		// printf("im still in while\n ID : %d\n", philo->id);
	}
	return (NULL);
}

// void	ft_creat_philo(int i, t_philos *philos)
// {
// 	pthread_create(&(philos->philo[i]->philo), NULL, routin,
// 		(philos->philo[i]));
// }

void	ft_childs(int i, t_philos *philos)
{
	int	time;

	pthread_create(&(philos->philo[i]->philo), NULL, routin, philos->philo[i]);
	while (42)
	{
		time = get_time();
		sem_wait(philos->philo[i]->meal_check);
		if (philos->philo[i]->number_of_eats != -1)
			if (!(check_eats(philos->philo[i])))
				exit(1);
		if (check_philo_life(philos->philo[i], i, time))
			exit(1);
		sem_post(philos->philo[i]->meal_check);
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
		// init_forks(&philos, philos.philo[i]->id);
		if (process == 0)
		{
			ft_childs(i, &philos);
			return (0);
		}
		i++;
	}
	waitpid(0, NULL, 0);
	// while (wait(NULL) != -1)
	// 		;
}
