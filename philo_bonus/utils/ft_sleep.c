/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 23:32:16 by aamoussa          #+#    #+#             */
/*   Updated: 2022/07/19 19:16:54 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_usleep(int time)
{
	size_t	i;

	i = get_time();
	while (1)
	{	
		if (get_stamp(i, get_time()) >= time)
			break ;
		usleep(50);
	}
}
