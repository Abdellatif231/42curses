/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_I.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 23:23:18 by amaaouni          #+#    #+#             */
/*   Updated: 2024/09/11 00:43:52 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print(const char *s, t_philo *philo)
{
    pthread_mutex_lock(&philo->table->print);
	if (!get_dead(philo->table))
		printf("%lu : %d %s\n", get_current_time() - philo->table->start, philo->id, s);
    pthread_mutex_unlock(&philo->table->print);
}

void    eating(t_philo *philo)
{
    pthread_mutex_lock(&philo->table->forks[philo->right_fork - 1]);
    pthread_mutex_lock(&philo->table->forks[philo->left_fork - 1]);
    print("has taken the fork", philo);
    print("is eating", philo);
	set_last_meal(philo);
    ft_usleep(philo->table->eat_time);
    pthread_mutex_unlock(&philo->table->forks[philo->right_fork - 1]);
    pthread_mutex_unlock(&philo->table->forks[philo->left_fork - 1]);
}

void    *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
		usleep(200);
    while (1)
    {
		if (get_dead(philo->table))
			break;
        eating(philo);
        thinking(philo);
        sleeping(philo);
    }
    return NULL;
}
