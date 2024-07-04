/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:19:26 by junhhong          #+#    #+#             */
/*   Updated: 2024/07/04 17:59:08 by junhhong         ###   ########.fr       */
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
	if (argc > 5)
		args->not = ft_atoi(argv[5]);
	else
		args->not = INT_MAX;
	args->is_died = 0;
	args->start_time = 0;
	args->start_time = get_time();
	args->all_full = 0;
	printf("nop:%d ttd:%d tte:%d tts:%d not:%d\n", args->nop, args->ttd, args->tte, args->tts, args->not);
	pthread_mutex_init (&args->announce_lock, NULL);
	// if (argc == 6)
	// 	args->not = ft_atoi(argv[5]);
	// else
	// 	args->not = 0;
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
		args->philo_struct[i].finished = 0;
		args->philo_struct[i].last_eat = (long)args->start_time;
		args->philo_struct[i].meals = 0;
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
	args->philo_struct[philo_index].last_eat = get_time();
	pthread_mutex_unlock(args->philo_struct[philo_index].l_fork);
	pthread_mutex_unlock(args->philo_struct[philo_index].r_fork);
}

void	fork_take(t_args *args, int	philo_index)
{
	long	time;
	
	pthread_mutex_lock(args->philo_struct[philo_index].l_fork);
	pthread_mutex_lock(args->philo_struct[philo_index].r_fork);
	args->philo_struct[philo_index].last_eat = get_time() + (args->tte * 1000);
	time = get_time() - args->start_time;
	announce(args, philo_index, TAKE_FORK);
	announce(args, philo_index, EATING);
	if (args->not >= 0)
		args->philo_struct[philo_index].meals ++ ;
	usleep(args->tte * 1000);
}

long	get_time()
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	sleeping(t_args *args, int philo_index)
{
	announce(args, philo_index, SLEEPING);
	usleep (args->tts * 1000);
}

void	thinking(t_args *args, int philo_index)
{
	announce(args,philo_index, THINKING);
}

void	*philo_action(void *arginfo)
{
	t_philo	*arginfo2;
	t_args *args;
	int	philo_index;

	arginfo2 = (void *)arginfo;
	args = arginfo2->args;
	philo_index = arginfo2->philo_index;
	while (arginfo2->args->is_died == 0 && args->all_full == 0)
	{
		fork_take(arginfo2->args, arginfo2->philo_index); // here
		if (args->philo_struct[philo_index].meals >= args->not)
			args->philo_struct[philo_index].finished = 1;
		if (args->all_full == 1)
		{
			fork_release(arginfo2->args, arginfo2->philo_index);
			sleeping(arginfo2->args, arginfo2->philo_index);
			return (NULL);
		}
		fork_release(arginfo2->args, arginfo2->philo_index);
		sleeping(arginfo2->args, arginfo2->philo_index);
		thinking(arginfo2->args, arginfo2->philo_index);
	}
	return (NULL);
}

void	*monitoring(void *args)
{
	int	i;
	int	sum;
	t_args	*args2;

	sum = 0;
	args2 = (t_args *)args;
	while (args2->is_died == 0)
	{
		i = 0;
		sum = 0;
		while (i < args2->nop)
		{
			if (args2->philo_struct[i].finished == 1)
				sum ++ ;
			if (sum == args2->nop)
				args2->all_full = 1;
			if (get_time() - args2->philo_struct[i].last_eat > (long)args2->ttd)
			{
				printf("not eat since:%ld ttd:%ld meals:%d phil_index:%d\n", get_time() - args2->philo_struct[i].last_eat, (long)args2->ttd, args2->philo_struct[i].finished,i);
				if(announce(args2, i, DIED) == 1)
					return (NULL);
				args2->is_died = 1;
			}
			i ++ ;
		}
	}
	return (NULL);
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
		usleep(100);
		i ++ ;
	}
	i = 0;
	while (i < nop)
	{
		pthread_join(args->philo_group[i], NULL);
		i ++ ;
	}
}

int	announce(t_args *args, int philo_index, char *msg)
{
	long	time;

	time = get_time() - args->start_time;
	pthread_mutex_lock(&args->announce_lock);
	if (args->is_died == 1)
	{
		pthread_mutex_unlock(&args->announce_lock);
		return (1);
	}
	if (args->is_died == 0)
		printf("%ld %d %s\n", time, philo_index, msg);
	pthread_mutex_unlock(&args->announce_lock);
	return (0);
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
