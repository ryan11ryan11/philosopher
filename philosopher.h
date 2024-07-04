#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>

# define TAKE_FORK "has taken a fork"
# define EATING "is eating"
# define SLEEPING "is sleeping"
# define THINKING "is thinking"
# define DIED "died"
# define INT_MAX 2147483647

typedef struct s_args
{
	int	nop; // number of philosopher
	int	ttd; // time to die
	int	tte; // time to eat
	int	tts; // time to sleep
	int	not; // number_of_times_each_philosopher_must_eat
	int	is_died;
	int	all_full;
	long	start_time;
	pthread_t	*philo_group;
	struct s_philo		*philo_struct;
	pthread_mutex_t		*fork;
	pthread_mutex_t		announce_lock;
}	t_args;

typedef struct s_arginfo
{
	int	philo_num;
	t_args	*args;
}	t_arginfo;

typedef struct s_philo
{
	int	philo_index;
	long	last_eat;
	int	meals;
	int	finished;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_args	*args;
}	t_philo;

int	ft_atoi(const char *nptr);

long	get_time(void);
int	announce(t_args *args, int philo_index, char *msg);
char	*ft_strchr(const char *s, int c);

#endif