#ifndef PHILO_H
#define	PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef pthread_mutex_t mutex_t;
typedef struct s_table	t_table;

typedef struct	s_philo {
    int			id;
    int			meals;
    size_t		last_meal_time;
    int			left_fork;
    int			right_fork;
    pthread_t	thread;
	t_table		*table;
}				t_philo;

typedef struct	s_table {
    int		num_philo;
    size_t	die_time;
    size_t	eat_time;
    size_t	sleep_time;
    int		num_meals;
	long	start;
	int		dead;
	int		full;
	mutex_t	death;
	mutex_t	print;
	mutex_t	last_meal;
	mutex_t	meals_lock;
	mutex_t	full_lock;
	mutex_t	*forks;
    t_philo	*philo;
}			t_table;

int		check_arg(int ac, char **av);
int		to_int(char *str);
int		ft_usleep(size_t milliseconds);
size_t  get_current_time(void);
void    print(const char *s, t_philo *philo);
void    eating(t_philo *philo);
void    sleeping(t_philo *philo);
void    thinking(t_philo *philo);
void    *routine(void *arg);
void    clear(t_table *table);
void    create_threads(t_table *table);
int 	philo_init(t_table *table);
void    table_init(t_table *table, int ac, char **av);
int		get_dead(t_table *table);
void    set_dead(t_table *table);
void    set_last_meal(t_philo *philo);
void    death_checker(t_table *table);
void    set_meals(t_philo *philo);
int		get_meals(t_philo *philo);
void    set_full(t_table *table);
int		get_full(t_table *table);

#endif
