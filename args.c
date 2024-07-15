/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhhong <junhhong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:21:10 by junhhong          #+#    #+#             */
/*   Updated: 2024/07/15 16:46:19 by junhhong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	is_alldigit(char *argv[])
{
	int	i;
	int	k;

	k = 0;
	i = 1;
	while (argv[i] != NULL)
	{
		while (argv[i][k] != '\0')
		{
			if (ft_isdigit(argv[i][k]) == 0)
				return (-1);
			k ++ ;
		}
		k = 0;
		i ++ ;
	}
	return (0);
}

int	set_args(t_args *args, char *argv[], int argc)
{
	if (is_alldigit(argv) == -1)
		return (-1);
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
	pthread_mutex_init (&args->announce_lock, NULL);
	if (args->nop < 0 || args->ttd < 0 || args->tte < 0 \
	|| args->tts < 0 || args->not < 0)
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
	if (set_args (args, argv, argc) == -1)
	{
		printf("argv value is not digit\n");
		return (0);
	}
	return (1);
}

void	one_philo(t_args *args)
{
	usleep(args->ttd * 1000);
	announce(args, 1, DIED);
}
