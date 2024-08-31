#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef pthread_mutex_t mutex_t;

typedef struct	s_philo {
    int		id;
    int		meals;
    long	last_meal_time;
    int		left_fork;
    int		right_fork;
    pthread_t	thread;
}		t_philo;

typedef struct	s_table {
    int		num_philo;
    int		die_time;
    int		eat_time;
    int		sleep_time;
    int		num_meals;
    mutex_t	*forks;
    mutex_t	id;
    t_philo	*philos;
}		t_table;

int	check_arg(int ac, char **av);
int	to_int(char *str);

