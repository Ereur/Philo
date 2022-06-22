
#include "philo.h"

void	ft_usleep(size_t time)
{
	size_t	i;
	time = time / 1000;
	while (time)
	{	
		usleep(200);
		time--;
	}
}