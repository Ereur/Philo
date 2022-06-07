/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamoussa <aamoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:49:03 by aamoussa          #+#    #+#             */
/*   Updated: 2022/06/06 15:49:24 by aamoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

int	ft_atoi(const char *str)
{
	int				i;
	unsigned long	num;
	int				sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((*(str + i) >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (*(str + i) == '-')
		sign = -1;
	if (*(str + i) == '-' || *(str + i) == '+')
		i++;
	while (*(str + i) && *(str + i) >= '0' && *(str + i) <= '9')
	{
		if (num > LONG_MAX)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		num = num * 10 + (*(str + i++) - '0');
	}
	return ((int)num * sign);
}