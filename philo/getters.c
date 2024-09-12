/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:43:17 by amaaouni          #+#    #+#             */
/*   Updated: 2024/09/11 22:44:31 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_full(t_table *table)
{
	int	full;

	pthread_mutex_lock(&table->full_lock);
	full = table->full;
	pthread_mutex_unlock(&table->full_lock);
	return (full);
}

int	get_meals(t_philo *philo)
{
	int	meals;

	pthread_mutex_lock(&philo->table->meals_lock);
	meals = philo->meals;
	pthread_mutex_unlock(&philo->table->meals_lock);
	return (meals);
}

size_t	get_last_meal(t_philo *philo)
{
	size_t	meal_time;

	pthread_mutex_lock(&philo->table->last_meal);
	meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->table->last_meal);
	return (meal_time);
}

int	get_dead(t_table *table)
{
	int	bola;

	pthread_mutex_lock(&table->death);
	bola = table->dead;
	pthread_mutex_unlock(&table->death);
	return (bola);
}
