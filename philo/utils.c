/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:48:06 by amaaouni          #+#    #+#             */
/*   Updated: 2024/09/11 23:47:31 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_usleep(size_t milliseconds)
{
	size_t	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print(const char *s, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	if (!get_dead(philo->table))
		printf("%lu : %d %s\n", get_current_time() - philo->table->start,
			philo->id, s);
	pthread_mutex_unlock(&philo->table->print);
}

void	clear(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philo)
	{
		pthread_join(table->philo[i].thread, NULL);
		i++;
	}
	i = 0;
	while (i < table->num_philo)
	{
		pthread_mutex_destroy(&table->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&table->print);
	pthread_mutex_destroy(&table->death);
	pthread_mutex_destroy(&table->last_meal);
	pthread_mutex_destroy(&table->meals_lock);
	pthread_mutex_destroy(&table->full_lock);
	free(table->philo);
	free(table->forks);
}
