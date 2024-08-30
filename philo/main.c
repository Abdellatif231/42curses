#include "philo.h"

void	*routine(void *arg)
{
	t_table *table = (t_table *)arg;
	pthread_mutex_lock(&table->id);
	(table->philos.id)++;
	printf("philo id -> %d\n", table->philos.id);
	pthread_mutex_unlock(&table->id);
	return NULL;
}

int	main(int ac, char **av)
{
	t_table	table;
	int	i;

	if ((ac != 5 && ac != 6) || !check_arg(ac, av))
	{
		printf("not a valid arguments\n");
		return 1;
	}
	table.num_philo = to_int(av[1]);
	table.die_time = to_int(av[2]);
	table.eat_time = to_int(av[3]);
	table.sleep_time = to_int(av[4]);
	if (ac == 6)
		table.num_meals = to_int(av[5]);
	pthread_mutex_init(&table.id, NULL);
	i = 0;
	table.philos.id = 0;
	while (i < table.num_philo)
	{
		pthread_create(&table.philos.thread, NULL, routine, &table);
		i++;
	}
	i = 0;
	while (i < table.num_philo)
	{
		pthread_join(table.philos.thread, NULL);
		i++;
	}
	return 0;
}
