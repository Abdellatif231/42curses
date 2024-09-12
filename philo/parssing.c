/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:23:22 by amaaouni          #+#    #+#             */
/*   Updated: 2024/09/11 23:47:03 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	to_int(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == '+' && (str[i + 1] > 47 && str[i + 1] < 58))
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	if (str[i])
		return (-1);
	return (num);
}

int	check_arg(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (to_int(av[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}

void	table_init(t_table *table, int ac, char **av)
{
	table->dead = 0;
	table->full = 0;
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
	pthread_mutex_init(&table->death, NULL);
	pthread_mutex_init(&table->last_meal, NULL);
	pthread_mutex_init(&table->meals_lock, NULL);
	pthread_mutex_init(&table->full_lock, NULL);
}

int	allocate(t_table *table)
{
	table->philo = malloc(sizeof(t_philo) * table->num_philo);
	if (!table->philo)
		return (0);
	table->forks = malloc(sizeof(t_mutex) * table->num_philo);
	if (!table->forks)
	{
		free(table->philo);
		return (0);
	}
	return (1);
}

int	philo_init(t_table *table)
{
	int	i;

	if (!allocate(table))
		return (0);
	i = 0;
	while (i < table->num_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].meals = 0;
		table->philo[i].last_meal_time = table->start;
		if (i + 1 == table->num_philo)
			table->philo[i].left_fork = 1;
		else
			table->philo[i].left_fork = i + 2;
		table->philo[i].right_fork = i + 1;
		table->philo[i].table = table;
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	return (1);
}
