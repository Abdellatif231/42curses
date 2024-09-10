/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:48:06 by amaaouni          #+#    #+#             */
/*   Updated: 2024/09/11 00:23:05 by amaaouni         ###   ########.fr       */
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

void    sleeping(t_philo *philo)
{
    print("is sleeping", philo);
    ft_usleep(philo->table->sleep_time);
}

void    thinking(t_philo *philo)
{
    print("is thinking", philo);
}

void    table_init(t_table *table, int ac, char **av)
{
    table->dead = 0;
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
}

int philo_init(t_table *table)
{
    int i;

    table->philo = malloc(sizeof(t_philo) * table->num_philo);
    if (!table->philo)
        return 0;
    table->forks = malloc(sizeof(mutex_t) * table->num_philo);
    if (!table->forks)
    {
        free(table->philo);
        return 0;
    }
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
    return 1;
}

void    create_threads(t_table *table)
{
    int i;

    i = 0;
    while (i < table->num_philo)
    {
        pthread_create(&table->philo[i].thread, NULL, routine, &table->philo[i]);
        i++;
    }
}

void    clear(t_table *table)
{
    int i;

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
    free(table->philo);
    free(table->forks);
}

