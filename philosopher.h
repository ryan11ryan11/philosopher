#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

typedef struct s_args
{
	int	nop; // number of philosopher
	int	ttd; // time to die
	int	tte; // time to eat
	int	tts; // time to sleep
	int	not; // number_of_times_each_philosopher_must_eat
	struct timeval start_time;
	pthread_t	*philo_group;
	struct s_philo		*philo_struct;
	pthread_mutex_t		*fork;
}	t_args;

typedef struct s_arginfo
{
	int	philo_num;
	t_args	*args;
}	t_arginfo;

typedef struct s_philo
{
	int	philo_index;
	struct timeval	last_eat;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_args	*args;
}	t_philo;

int	ft_atoi(const char *nptr);

#endif