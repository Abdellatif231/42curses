#include "philo.h"

void	table_init(t_table *table, int ac, char **av)
{
	table->dead = 0;
    table->num_philo = to_int(av[1]);
    table->die_time = to_int(av[2]);
    table->eat_time = to_int(av[3]);
    table->sleep_time = to_int(av[4]);
	table->start = get_current_time();
    if (ac == 6)
        table->num_meals = to_int(av[5]);
	else
		table->num_meals = -1;
	pthread_mutex_init(&table->print, NULL);
	pthread_mutex_init(&table->died, NULL);
}

int	philo_init(t_table *table)
{
	int	i;

	table->philo = malloc(sizeof(t_philo) * table->num_philo);
	if (!table->philo)
		return 0;
    table->forks = malloc(sizeof(mutex_t) * table->num_philo);
	if (!table->forks)
	{
		free(table->philo);
		return 0;
	}
    i = 0;
    while (i < table->num_philo)
    {
        table->philo[i].id = i + 1;
        table->philo[i].meals = 0;
        table->philo[i].last_meal_time = table->start;
        table->philo[i].left_fork = (i + 2) % table->num_philo;
        table->philo[i].right_fork = i + 1;
        table->philo[i].table = table;
        pthread_mutex_init(&table->forks[i], NULL);
        i++;
    }
	return 1;
}

void	create_threads(t_table *table)
{
	int	i;

	i = 0;
    while (i < table->num_philo)
    {
        pthread_create(&table->philo[i].thread, NULL, routine, &table->philo[i]);
        i++;
    }
}

void	clear(t_table *table)
{
	int	i;

    i = 0;
    while (i < table->num_philo)
    {
        pthread_join(table->philo[i].thread, NULL);
        i++;
    }
    i = 0;
    while (i < table->num_philo)
    {
        pthread_mutex_destroy(&table->forks[i]);
        i++;
    }
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->died);
	free(table->philo);
	free(table->forks);
}

int	main(int ac, char **av)
{
	t_table	table;

	if ((ac != 5 && ac != 6) || !check_arg(ac, av))
	{
		printf("not a valid arguments\n");
		return 1;
	}
	table_init(&table, ac, av);
	if (!philo_init(&table))
		return 1;
	create_threads(&table);
	int	i;

	while (!table.dead)
	{
		i = 0;
		while (i < table.num_philo)
		{
			pthread_mutex_lock(&table.died);
			if (get_current_time() - table.philo[i].last_meal_time >= table.die_time)
			{
				print("died", &table.philo[i]);
				table.dead = 1;
			}
			pthread_mutex_unlock(&table.died);
			i++;
		}
	}
	clear(&table);
	return 0;
}
