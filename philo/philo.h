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
    int		id;
    int		meals;
    size_t	last_meal_time;
    int		left_fork;
    int		right_fork;
    pthread_t	thread;
	t_table		*table;
}		t_philo;

typedef struct	s_table {
    int		num_philo;
    size_t	die_time;
    size_t	eat_time;
    size_t	sleep_time;
    int		num_meals;
	long	start;
	int		dead;
	mutex_t	died;
    mutex_t	*forks;
	mutex_t	print;
    t_philo	*philo;
}		t_table;

int		check_arg(int ac, char **av);
int		to_int(char *str);
int		ft_usleep(size_t milliseconds);
size_t  get_current_time(void);
void    print(const char *s, t_philo *philo);
void    eating(t_philo *philo);
void    sleeping(t_philo *philo);
void    thinking(t_philo *philo);
void    *routine(void *arg);

#endif
