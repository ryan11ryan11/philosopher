/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:19:26 by junhhong          #+#    #+#             */
/*   Updated: 2024/07/05 14:31:12 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	*monitoring(void *args)
{
	int		i;
	int		sum;
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
			{
				args2->all_full = 1;
				return (NULL);
			}
			if (get_time() - args2->philo_struct[i].last_eat > (long)args2->ttd)
			{
				if (announce (args2, i, DIED) == 1)
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
	int			nop;
	int			i;
	pthread_t	monitor;

	i = 0;
	nop = args->nop;
	pthread_create(&monitor, NULL, monitoring, args);
	while (i < nop)
	{
		pthread_create(&args->philo_group[i], NULL, \
		philo_action, &args->philo_struct[i]);
		usleep(1000);
		i ++ ;
	}
	i = 0;
	while (i < nop)
	{
		pthread_join(args->philo_group[i], NULL);
		i ++ ;
	}
	pthread_join(monitor, NULL);
}

int	main(int argc, char *argv[])
{
	t_args	args;

	if (argument_check(argc, argv, &args) == 0)
		return (0);
	args.philo_group = philo_maker(&args);
	if (args.philo_group == NULL)
		return (0);
	if (args.nop == 1)
	{
		one_philo(&args);
		return (0);
	}
	args.fork = forkmaker(&args);
	init(&args);
	free (args.philo_group);
	free (args.philo_struct);
	free (args.fork);
}
