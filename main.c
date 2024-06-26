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
	philo_group = (pthread_t *)malloc((args->nop - 1) * sizeof(pthread_t));
	while (i < args->nop - 1)
	{
		t_philo-> 
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
		fork[num_philo - 1].is_occupied = 0;
		num_philo -- ;
	}
	return (fork);
}

void	fork_take()
{

}

void	*philo_action(void *i, t_args *args)
{
	(void) i;
	fork_take();
	return NULL;
}

void	init(t_args *args)
{
	int	nop;
	int	i;

	i = 0;
	nop = args->nop;
	while (i < nop)
	{
		pthread_create(&args->philo_group[i], NULL, philo_action, NULL);
		printf("philo made\n");
		pthread_join(args->philo_group[i], NULL);
		i ++ ;
	}
}

int main(int argc, char *argv[])
{
	t_args	args;
	t_philo	philo;

	printf("argv: %s %s %s %s %s\n", argv[1],argv[2],argv[3],argv[4],argv[5]);
	if (argument_check(argc, argv, &args) == 0)
		return (0);
	args.philo_group = philo_maker(&args);
	if (args.philo_group == NULL)
		return (0);
	args.fork = forkmaker(&args);
	init(&args);
	free (args.philo_group);
	free (fork); 
}
