/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:23:06 by junhhong          #+#    #+#             */
/*   Updated: 2024/07/05 14:23:51 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

long	get_time()
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
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
			announce(args, philo_index, SLEEPING);
			return (NULL);
		}
		fork_release(arginfo2->args, arginfo2->philo_index);
		sleeping(arginfo2->args, arginfo2->philo_index);
		thinking(arginfo2->args, arginfo2->philo_index);
	}
	return (NULL);
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
