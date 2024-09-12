/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:23:18 by amaaouni          #+#    #+#             */
/*   Updated: 2024/09/11 23:07:52 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating_alone(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->right_fork - 1]);
	print("has taken the fork", philo);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork - 1]);
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

void	eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->forks[philo->right_fork - 1]);
	pthread_mutex_lock(&philo->table->forks[philo->left_fork - 1]);
	print("has taken the fork", philo);
	print("is eating", philo);
	set_last_meal(philo);
	ft_usleep(philo->table->eat_time);
	set_meals(philo);
	pthread_mutex_unlock(&philo->table->forks[philo->right_fork - 1]);
	pthread_mutex_unlock(&philo->table->forks[philo->left_fork - 1]);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->num_philo == 1)
	{
		eating_alone(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		usleep(50);
	while (1)
	{
		if (get_dead(philo->table) || get_full(philo->table))
			break ;
		eating(philo);
		thinking(philo);
		sleeping(philo);
	}
	return (NULL);
}
