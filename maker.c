/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maker.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:17:35 by junhhong          #+#    #+#             */
/*   Updated: 2024/07/05 14:18:15 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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