/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 21:02:03 by amaaouni          #+#    #+#             */
/*   Updated: 2024/09/11 02:35:26 by amaaouni         ###   ########.fr       */
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

size_t	get_last_meal(t_philo *philo)
{
	size_t	meal_time;
	pthread_mutex_lock(&philo->table->last_meal);
	meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->table->last_meal);
	return meal_time;
}

void	set_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->meals_lock);
	philo->meals++;
	pthread_mutex_unlock(&philo->table->meals_lock);
}

int	get_meals(t_philo *philo)
{
	int	meals;
    pthread_mutex_lock(&philo->table->meals_lock);
    meals = philo->meals;
    pthread_mutex_unlock(&philo->table->meals_lock);
	return meals;
}

int	get_full(t_table *table)
{
	int full;

    pthread_mutex_lock(&table->full_lock);
    full = table->full;
    pthread_mutex_unlock(&table->full_lock);
	return full;
}

void	set_full(t_table *table)
{
	pthread_mutex_lock(&table->full_lock);
	table->full = 1;
	pthread_mutex_unlock(&table->full_lock);
}

void	death_checker(t_table *table)
{

	int	i;

	while (!get_dead(table))
	{
		i = 0;
		while (i < table->num_philo)
		{
			if (get_current_time() - get_last_meal(&table->philo[i]) >= table->die_time)
			{
				print("died", &table->philo[i]);
				set_dead(table);
				break;
			}
	//		if (get_meals(&table->philo[i]) < table->num_meals)
	//			set_full(table);
			i++;
		}
	//	if (!get_full(table))
	//		break;
		usleep(50);
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
