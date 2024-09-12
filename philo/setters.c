/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 22:44:53 by amaaouni          #+#    #+#             */
/*   Updated: 2024/09/11 22:45:51 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

void	set_meals(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->meals_lock);
	philo->meals++;
	pthread_mutex_unlock(&philo->table->meals_lock);
}

void	set_full(t_table *table)
{
	pthread_mutex_lock(&table->full_lock);
	table->full = 1;
	pthread_mutex_unlock(&table->full_lock);
}
