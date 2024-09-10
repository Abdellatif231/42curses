/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:02:03 by amaaouni          #+#    #+#             */
/*   Updated: 2024/09/11 00:37:08 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_dead(t_table *table)
{
	int	bola;
	pthread_mutex_lock(&table->death);
	bola = table->dead;
	pthread_mutex_unlock(&table->death);
	return bola;
}

void	set_dead(t_table *table)
{
    pthread_mutex_lock(&table->death);
    table->dead = 1; 
    pthread_mutex_unlock(&table->death);
}

void	set_last_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->last_meal);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->table->last_meal);
}

void	death_checker(t_table *table)
{

	int	i;

	while (!get_dead(table))
	{
		i = 0;
		while (i < table->num_philo)
		{
			pthread_mutex_lock(&table->last_meal);
			if (get_current_time() - table->philo[i].last_meal_time >= table->die_time)
			{
				print("died", &table->philo[i]);
				set_dead(table);
				pthread_mutex_unlock(&table->last_meal);
				break;
			}
			pthread_mutex_unlock(&table->last_meal);
			i++;
		}
	}
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
	death_checker(&table);
	clear(&table);
	return 0;
}
