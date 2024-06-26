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

void *function1(void *s)
{
	int i = 0;
	int k = 0;
	pthread_mutex_lock(&mutex1);
	while(i < 12)
	{
		printf("%s :: %d\n",(char *)s, i);
		i ++ ;
	}
	pthread_mutex_unlock(&mutex1);
	return NULL;
}

int main()
{
	int i = 0;
	pthread_t thread[2];

	pthread_mutex_init(&mutex1, NULL);
	pthread_create(&thread[0], NULL, function1, (void *)"thread 0");
	usleep (100);
	pthread_create(&thread[1], NULL, function1, (void *)"thread 1");
	usleep (100);
	pthread_create(&thread[2], NULL, function1, (void *)"thread 2");
	usleep (100);
	pthread_mutex_destroy(&mutex1);
	return (0);
}