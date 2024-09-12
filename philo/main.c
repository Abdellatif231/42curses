/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:02:03 by amaaouni          #+#    #+#             */
/*   Updated: 2024/09/11 23:45:26 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		pthread_create(&table->philo[i].thread, NULL, routine,
			&table->philo[i]);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_table	table;

	if ((ac != 5 && ac != 6) || !check_arg(ac, av))
	{
		printf("not a valid arguments\n");
		return (1);
	}
	table_init(&table, ac, av);
	if (!philo_init(&table))
		return (1);
	create_threads(&table);
	death_checker(&table);
	clear(&table);
	return (0);
}
