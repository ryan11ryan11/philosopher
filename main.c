/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:19:26 by junhhong          #+#    #+#             */
/*   Updated: 2024/07/02 13:11:11 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

pthread_mutex_t mutex1;

int	set_args(t_args *args, char *argv[], int argc)
{
	args->nop = ft_atoi(argv[1]);
	args->ttd = ft_atoi(argv[2]);
	args->tte = ft_atoi(argv[3]);
	args->tts = ft_atoi(argv[4]);
	args->is_died = 0;
	args->start_time = 0;
	args->start_time = get_time();
	printf("nop:%d ttd:%d tte:%d tts:%d\n", args->nop, args->ttd, args->tte, args->tts);
	//printf("time_test:%ld\n",args->start_time.tv_sec); 
	if (argc == 6)
		args->not = ft_atoi(argv[5]);
	else
		args->not = 0;
	if (args->nop < 0 || args->ttd < 0 || args->tte < 0 || args->tts < 0 || args->not < 0)
		return (0);
	return (1);
}

int	argument_check(int argc, char *argv[], t_args *args)
{
	if (argc < 5 || argc > 6)
	{
		printf("Number of argument is not good\n");
		return (0);
	}
	if (set_args (args, argv, argc) == 0)
	{
		printf("Value of argv is smaller than 0\n");
		return (0);
	}
	return (1);
}

pthread_t	*philo_maker(t_args *args)
{
	pthread_t	*philo_group;
	int	i;

	i = 0;
	philo_group = (pthread_t *)malloc((args->nop) * sizeof(pthread_t));
	args->philo_struct = (t_philo *)malloc((args->nop) * sizeof(t_philo));
	while (i < args->nop)
	{
		args->philo_struct[i].philo_index = i;
		args->philo_struct[i].args = args;
		args->philo_struct[i].last_eat = get_time();
		i ++ ;
	}
	return (philo_group);
}

pthread_mutex_t	*forkmaker(t_args *args)
{
	int	i;

	i = 1;
	args->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * (args->nop));
	pthread_mutex_init (&args->fork[0], NULL);
	args->philo_struct[0].l_fork = &args->fork[0];
	args->philo_struct[0].r_fork = &args->fork[args->nop - 1];
	while (i < args->nop)
	{
		pthread_mutex_init (&args->fork[i], NULL);
		args->philo_struct[i].l_fork = &args->fork[i - 1];
		args->philo_struct[i].r_fork = &args->fork[i];
		i ++ ;
	}
	return (args->fork);
}

void	fork_release(t_args *args, int	philo_index)
{
	pthread_mutex_unlock(args->philo_struct[philo_index].l_fork);
	pthread_mutex_unlock(args->philo_struct[philo_index].r_fork);
}

void	fork_take(t_args *args, int	philo_index)
{
	long	time;
	
	pthread_mutex_lock(args->philo_struct[philo_index].l_fork);
	pthread_mutex_lock(args->philo_struct[philo_index].r_fork);
	time = get_time() - args->start_time;
	args->philo_struct[philo_index].last_eat = get_time();
	printf("%ld %d has taken a fork\n", time, philo_index);
	printf("%ld %d is eating\n", time, philo_index);
	usleep(args->tte);
}

long	get_time()
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec*1000 + time.tv_usec/1000);
}

void	sleeping(t_args *args, int philo_index)
{
	long	time;

	time = get_time() - args->start_time;
	printf("%ld %d is sleeping\n", time, philo_index);
	usleep (args->tts);
}

void	thinking(t_args *args, int philo_index)
{
	long	time;

	time = get_time() - args->start_time;
	printf("%ld %d is thinking\n", time, philo_index);
}

void	*philo_action(void *arginfo)
{
	t_philo	*arginfo2;

	arginfo2 = (void *)arginfo;
	fork_take(arginfo2->args, arginfo2->philo_index);
	fork_release(arginfo2->args, arginfo2->philo_index);
	sleeping(arginfo2->args, arginfo2->philo_index);
	thinking(arginfo2->args, arginfo2->philo_index);
	return (NULL);
}

void	*monitoring(void *args)
{
	int	i;
	long	time;
	t_args	*args2;

	args2 = (t_args *)args;
	i = 0;
	time = get_time() - args2->start_time;
	while (args2->is_died == 0)
	{
		i = 0;
		while (i < args2->nop)
		{
			//printf("%ld\n", get_time() - args2->philo_struct[i].last_eat);
			//printf("last eat:%ld current time:%ld", args2->philo_struct[i].last_eat, get_time());
			if (get_time() - args2->philo_struct[i].last_eat > args2->ttd)
			{
				printf("%ld %d has died\n", time, i);
				return ((void *)NULL);
			}
			i ++ ;
		}
	}
	return (void *)(NULL);
}

void	init(t_args *args)
{
	int	nop;
	int	i;
	pthread_t	monitor;

	i = 0;
	nop = args->nop;
	pthread_create(&monitor, NULL, monitoring, args);
	while (i < nop)
	{
		pthread_create(&args->philo_group[i], NULL, philo_action, &args->philo_struct[i]);
		i ++ ;
	}
	i = 0;
	while (i < nop)
	{
		pthread_join(args->philo_group[i], NULL);
		i ++ ;
	}
}

int main(int argc, char *argv[])
{
	t_args	args;

	if (argument_check(argc, argv, &args) == 0)
		return (0);
	args.philo_group = philo_maker(&args);
	if (args.philo_group == NULL)
		return (0);
	args.fork = forkmaker(&args);
	init(&args);
	free (args.philo_group);
	free (args.philo_struct);
	//free (fork); 
}
