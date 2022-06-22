#include "philo.h"

int	main()
{
	size_t time = get_time();
	size_t current_time = get_time();
	printf ("current time is %ld \n", get_stamp(time, current_time));
	ft_usleep(200 * 1000);
	current_time = get_time();
	printf ("current time is %ld", get_stamp(time, current_time));
}