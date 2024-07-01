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
		printf("philo %d made\n", i);
		args->philo_struct[i].L_fork = -2;
		args->philo_struct[i].R_fork = -2;
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
		num_philo -- ;
	}
	return (fork);
}

void	fork_take(t_args *args, int	philo_index)
{
	pthread_mutex_t	fork_mutex;

	pthread_mutex_init(&fork_mutex, NULL);
	pthread_mutex_lock(&fork_mutex);
	args->fork[philo_index].is_occupied = philo_index;
	if (philo_index == 1)
	{
		args->philo_struct[philo_index].L_fork = philo_index;
		args->philo_struct[philo_index].R_fork = args->nop - 1;
	}
	else
	{
		args->philo_struct[philo_index].L_fork = philo_index;
		args->philo_struct[philo_index].R_fork = philo_index - 1;
	}
	printf("%d has taken a fork\n", philo_index);
	pthread_mutex_unlock(&fork_mutex);
}

int	fork_available(t_fork *fork)
{
	if (fork->is_occupied >= 0)
		return (1);
	else
		return (0);
}

void	*philo_action(void *arginfo)
{
	t_arginfo	*arginfo2;
	int	philo_index;

	arginfo2 = (void *)arginfo;
	philo_index = arginfo2->philo_num;
	if (fork_available(&arginfo2->args->fork[philo_index]) != 0)
		fork_take(arginfo2->args, arginfo2->philo_num);
}

void	init(t_args *args)
{
	int	nop;
	t_arginfo	arginfo;
	int	i;

	i = 0;
	arginfo.args = args;
	nop = args->nop;
	while (i < nop)
	{
		arginfo.philo_num = i;
		pthread_create(&args->philo_group[i], NULL, philo_action, &arginfo);
		printf("philo %d goes to take a fork\n", i);
		usleep(100);
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
