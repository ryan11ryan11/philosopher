/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:19:26 by junhhong          #+#    #+#             */
/*   Updated: 2024/05/28 16:25:07 by junhhong         ###   ########.fr       */
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
	gettimeofday(&args->start_time, NULL);
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
		printf("philo %d made\n", i);
		i ++ ;
	}
	return (philo_group);
}

t_fork	*forkmaker(t_args *args)
{
	int	num_philo;
	t_fork	*fork;

	num_philo = args->nop;
	printf("num_philo = %d\n",num_philo);
	fork = (t_fork *)malloc(sizeof(t_fork) * (num_philo - 1));
	while (num_philo > 0)
	{
		fork[num_philo - 1].is_occupied = -1;
		fork[num_philo - 1].fork_index = num_philo - 1;
		num_philo -- ;
	}
	return (fork);
}

void	fork_release(t_args *args, int	philo_index)
{
	args->fork[philo_index].is_occupied = -2;
	if (philo_index == 0)
		args->fork[args-> nop - 1].is_occupied = -2;
	else
		args->fork[philo_index - 1].is_occupied = -2;
}

void	fork_take(t_args *args, int	philo_index)
{
	pthread_mutex_t	fork_mutex;

	pthread_mutex_init(&fork_mutex, NULL);
	pthread_mutex_lock(&fork_mutex);
	args->fork[philo_index].is_occupied = philo_index;
	if (philo_index == 0)
		args->fork[args-> nop - 1].is_occupied = philo_index;
	else
		args->fork[philo_index - 1].is_occupied = philo_index;
	gettimeofday(&(args->philo_struct[philo_index].last_eat), NULL);
	printf("%ld %d has taken a fork\n", args->philo_struct[philo_index].last_eat.tv_usec - args->start_time.tv_usec, philo_index);
	printf("%ld %d is eating\n", args->philo_struct[philo_index].last_eat.tv_usec - args->start_time.tv_usec, philo_index);
	usleep (args->tte);
	fork_release (args, philo_index);
	pthread_mutex_unlock(&fork_mutex);
}

int	fork_available(t_philo *arginfo)
{
	int	philo_index;
	t_args	*args;

	philo_index = arginfo->philo_index;
	args = arginfo->args;
	if (philo_index == 0)
	{
		if (args->fork[philo_index].is_occupied >= 0 || \
			args->fork[args->nop - 1].is_occupied >= 0)
			return (0);
		else
			return (1);
	}
	else
	{
		if (args->fork[philo_index].is_occupied >= 0 || \
			args->fork[philo_index - 1].is_occupied >= 0)
			return (0);
		else
			return (1);
	}
	return (0);
}

int fork_wait(t_philo	*arginfo)
{
	if (arginfo->philo_index == 0)
	{
		while (arginfo->args->fork[arginfo->philo_index].is_occupied >= 0 || \
			arginfo->args->fork[arginfo->args->nop - 1].is_occupied >= 0)
			usleep(1);
	}
	else
		while (arginfo->args->fork[arginfo->philo_index].is_occupied >= 0 || \
		arginfo->args->fork[arginfo->philo_index - 1].is_occupied >= 0)
			usleep(1);
	fork_take (arginfo->args, arginfo->philo_index);
	return (1);
}

void	*philo_action(void *arginfo)
{
	t_philo	*arginfo2;

	arginfo2 = (void *)arginfo;
	if (fork_available(arginfo2) == 1)
		fork_take(arginfo2->args, arginfo2->philo_index);
	else
		fork_wait(arginfo2);
	return (NULL);
}

void	init(t_args *args)
{
	int	nop;
	int	i;

	i = 0;
	nop = args->nop;
	while (i < nop)
	{
		pthread_create(&args->philo_group[i], NULL, philo_action, &args->philo_struct[i]);
		//usleep(100);
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

	printf("argv: %s %s %s %s %s\n", argv[1],argv[2],argv[3],argv[4],argv[5]);
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
