#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

void	*fthread()
{
	printf("thread number \n");
	return NULL;
}

int		main()
{
	pthread_t	t[5];
	int	i;

	i = 0;
	while (i < 5)
	{
		pthread_create(&t[0], NULL, fthread, NULL);
		i++;
	}
	i = 0;
	while (i < 5)
	{
		pthread_join(t[0], NULL);
		i++;
	}
	return 0;
}
		
