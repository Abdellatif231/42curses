#include "philo.h"

void	think(t_table *data)
{
	printf("%d : is thinking\n", data->philos->id);
}

void	*routine(void *arg)
{
	t_table *table = (t_table *)arg;
	think(table);
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
	table.philos = malloc(sizeof(t_philo) * table.num_philo);

	i = 0;
	table.philos->id = 0;
	while (i < table.num_philo)
	{
		table.philos->id = i + 1;
		pthread_create(&table.philos[i].thread, NULL, routine, &table);
		i++;
	}
	i = 0;
	while (i < table.num_philo)
	{
		pthread_join(table.philos->thread, NULL);
		i++;
	}
	return 0;
}
