/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:49:41 by amaaouni          #+#    #+#             */
/*   Updated: 2024/09/11 22:56:20 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	starved(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		if (get_current_time()
			- get_last_meal(&table->philo[i]) >= table->die_time)
		{
			print("died", &table->philo[i]);
			set_dead(table);
			return (1);
		}
		i++;
	}
	return (0);
}

int	enough_food(t_table *table)
{
	int	i;
	int	bola;

	i = 0;
	bola = 0;
	while (i < table->num_philo)
	{
		if (get_meals(&table->philo[i]) < table->num_meals)
			bola = 1;
		i++;
	}
	if (!bola)
		return (1);
	return (0);
}

void	death_checker(t_table *table)
{
	while (!get_dead(table))
	{
		if (starved(table))
			break ;
		if (table->num_meals != -1 && enough_food(table))
		{
			set_full(table);
			break ;
		}
		usleep(50);
	}
}
