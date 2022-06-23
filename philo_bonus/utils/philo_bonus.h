/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:56:32 by aamoussa          #+#    #+#             */
/*   Updated: 2022/06/23 17:01:55 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include  <sys/time.h>
# include <semaphore.h>

typedef struct s_philo
{
	int					id;
	pthread_t			philo;
	sem_t				*right_fork;
	sem_t				*left_fork;
	int					number_of_eats;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_of_philos;
	size_t				last_meal;
	sem_t				*meal_check;
	size_t				curent_time;
	sem_t				*writing;
	int					count_eats;
}	t_philo;

typedef struct s_philos
{
	t_philo			**philo;
	sem_t			forks[200];
	int				nb_of_philos;
	pthread_mutex_t	writing;

}	t_philos;

int		ft_atoi(const char *str);
//init phiosophers forks and setup data
int		get_stamp(size_t a, size_t b);
size_t	get_time(void);
void	ft_usleep(int time);
void	print_action(char *message, t_philo *philos);
void	philo_eats(t_philo *philo);
int		ft_atoi(const char *str);
void	ft_init_mutex(t_philos *philos);
void	ft_init_philos(t_philos *philos, int ac, char **argv);
void	ft_lunch_philos(t_philos *philos);
void	init_forks(t_philos *philos, int id);
#endif