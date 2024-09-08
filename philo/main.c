#include "philo.h"

void	print(const char *s, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%lu : %d %s\n", get_current_time() - philo->table->start, philo->id, s);
	pthread_mutex_unlock(&philo->table->print);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->right_fork - 1]);
	pthread_mutex_lock(&philo->table->forks[philo->left_fork - 1]);
	print("has taken the fork", philo);
	print("is eating", philo);
	philo->table->last_meal_time = get_current_time();
	ft_usleep(philo->table->eat_time);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork - 1]);
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork - 1]);
}

void	sleeping(t_philo *philo)
{
	print("is sleeping", philo);
	ft_usleep(philo->table->sleep_time);
}

void	thinking(t_philo *philo)
{
	print("is thinking", philo);
}

void	*routine(void *arg)
{
	t_philo *philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		sleeping(philo);
	int i = 5;
	while (i)
	{
		eating(philo);
		thinking(philo);
		sleeping(philo);
		i--;
	}
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
	pthread_mutex_init(&table.print, NULL);
	if (ac == 6)
		table.num_meals = to_int(av[5]);
	table.philo = malloc(sizeof(t_philo) * table.num_philo);
	table.forks = malloc(sizeof(mutex_t) * table.num_philo);
	i = 0;
	table.philo->id = 0;
	while (i < table.num_philo)
	{
		table.philo[i].id = i + 1;
		table.philo[i].meals = 0;
		table.philo[i].last_meal_time = 0;
		table.philo[i].left_fork = i + 2 % table.num_philo;
		table.philo[i].right_fork = i + 1;
		table.philo[i].table = &table;
		pthread_mutex_init(&table.forks[i], NULL);
		i++;
	}
	table.start = get_current_time();
	i = 0;
	while (i < table.num_philo)
	{
		pthread_create(&table.philo[i].thread, NULL, routine, &table.philo[i]);
		i++;
	}
	i = 0;
	while (i < table.num_philo)
	{
		pthread_join(table.philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < table.num_philo)
	{
		pthread_mutex_destroy(&table.forks[i]);
		i++;
	}
	return 0;
}
