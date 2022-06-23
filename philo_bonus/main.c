/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 18:42:50 by aamoussa          #+#    #+#             */
/*   Updated: 2022/06/23 20:07:11 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo_bonus.h"

int x;

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
void	*routin(void *data)
{
	int i = 0;
	t_data *dat = (t_data *)data;
	
	int *a;
	a = dat->a;
	while(i < 100000)
	{
		(*a)++;
		i++;
	}
	return (NULL);
}

int	main(int ac, char **argv)
{
	pid_t	id;
	t_data	data;
	
	data.a = &x;
	
	data.mutex = sem_open("/mysem", O_CREAT, 0644);
	id = my_fork();
	if (id == 0)
	{
		printf("im in child\n");
		pthread_create(&data.philo,NULL,routin,&data);
		pthread_join(data.philo,NULL);
		exit(1);
	}
	// id = my_fork();
	// if (id == 0)
	// {
	// 	printf("im in sec child\n");
	// 	int i = 0;
	// 	// while (1)
	// 	while (i < 100000)
	// 	{	
	// 		x++;
	// 		i++;
	// 	}
	// 	printf("im out from sec\n");
	// 	exit(1);
	// }
	// printf("%d", a);
	while (wait(NULL) != -1)
		;
	printf("test : %d\n", x);	
}
