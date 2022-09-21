/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:21:09 by aamoussa          #+#    #+#             */
/*   Updated: 2022/09/21 23:33:48 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

size_t	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_isdigit(int c)
{
	if ((c >= 48 && c <= 57))
		return (1);
	return (0);
}

void	ft_check_args(int ac, char **argv)
{
	int	i;

	i = 0;
	if (ac > 6)
	{	
		printf("Invalid Input\n");
		exit(1);
	}
	ac--;
	while (ac)
	{
		i = 0;
		while (argv[ac][i])
		{
			if (!ft_isdigit(argv[ac][i++]))
			{
				printf("Invalid Input\n");
				exit(1);
			}	
		}
		ac--;
	}	
}

int	main(int ac, char **argv)
{
	t_philos	philos;

	ft_check_args(ac, argv);
	ft_init_philos(&philos, ac, argv);
	ft_lunch_philos(&philos);
}
