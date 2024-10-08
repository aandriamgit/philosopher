#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int				primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
pthread_mutex_t	mutex;

void	*routine(void *arg)
{
	int	index;
	int	sum;

	index = *(int *)arg;
	sum = primes[index];
	pthread_mutex_lock(&mutex);
	printf("local sum: %d\n", sum);
	pthread_mutex_unlock(&mutex);
	*(int *)arg = sum;
	return (arg);
}

int	main(int argc, char **argv)
{
	pthread_t	th[10];
	int			i;
	int			*a;
	int			globalsum;
	int			*r;

	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 10)
	{
		a = malloc(sizeof(int));
		*a = i;
		if (pthread_create(&th[i], NULL, &routine, a) != 0)
			printf("voici un message d'erreur\n");
		i++;
	}
	globalsum = 0;
	i = 0;
	while (i < 10)
	{
		if (pthread_join(th[i], (void **)&r) != 0)
			printf("voici un message d'erreur\n");
		globalsum += *r;
		free(r);
		i++;
	}
	printf("le sum est de: %d\n", globalsum);
	pthread_mutex_destroy(&mutex);
}
