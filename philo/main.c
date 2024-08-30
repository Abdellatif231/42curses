#include "philo.h"

int	main(int ac, char **av)
{
	t_table	table;

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
	printf("%d\n", table.num_philo);
	return 0;
}
