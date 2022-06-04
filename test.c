#include <pthread.h>
#include <stdio.h>

int x = 0;

void *routine(void *mutex)
{
	int i = 0;
	int d;

	printf("%d\n", d);
	while(i++ < 100000000)
	{
		if ((d = pthread_mutex_lock(mutex)))
			perror("Error : first thread mutex_lock :");
		x++;
		if (pthread_mutex_unlock(mutex))
			perror("Error : first thread mutex_unlock :");
	}
	return (NULL);
}

int main()
{
	pthread_t i[2];
	pthread_mutex_t	mutex;

	if (pthread_mutex_init(&mutex, NULL))
	{
		perror("Error : mutex_init");
	}
	if (pthread_create(&i[0], NULL, routine, &mutex) != 0)
	{
		perror("Error1");
	}
	if (pthread_create(&i[1], NULL, routine, &mutex) != 0)
	{
		perror("Error2");
	}
	int ok = 0;
	while (ok < 2)
	{
		if (pthread_join(i[ok++],NULL))
		{
			perror("Error join failled : ");
		}
	}
	printf("%d\n",x);
}