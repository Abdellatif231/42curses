/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaaouni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 23:44:17 by amaaouni          #+#    #+#             */
/*   Updated: 2024/09/11 23:44:24 by amaaouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mutex;
typedef struct s_table	t_table;

typedef struct s_philo
{
	int					id;
	int					meals;
	size_t				last_meal_time;
	int					left_fork;
	int					right_fork;
	pthread_t			thread;
	t_table				*table;
}						t_philo;

typedef struct s_table
{
	int					num_philo;
	size_t				die_time;
	size_t				eat_time;
	size_t				sleep_time;
	int					num_meals;
	long				start;
	int					dead;
	int					full;
	t_mutex				death;
	t_mutex				print;
	t_mutex				last_meal;
	t_mutex				meals_lock;
	t_mutex				full_lock;
	t_mutex				*forks;
	t_philo				*philo;
}						t_table;

int						check_arg(int ac, char **av);
int						to_int(char *str);
int						ft_usleep(size_t milliseconds);
size_t					get_current_time(void);
void					print(const char *s, t_philo *philo);
void					eating(t_philo *philo);
void					sleeping(t_philo *philo);
void					thinking(t_philo *philo);
void					*routine(void *arg);
void					clear(t_table *table);
void					create_threads(t_table *table);
int						philo_init(t_table *table);
void					table_init(t_table *table, int ac, char **av);
int						get_dead(t_table *table);
void					set_dead(t_table *table);
size_t					get_last_meal(t_philo *philo);
void					set_last_meal(t_philo *philo);
void					death_checker(t_table *table);
void					set_meals(t_philo *philo);
int						get_meals(t_philo *philo);
void					set_full(t_table *table);
int						get_full(t_table *table);
int						enough_food(t_table *table);

#endif
