/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:11:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/03/23 21:26:04 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	cnt = 0;

typedef struct	__arg_t
{
	char			*name;
	pthread_mutex_t	*mutex;
} arg_t;

void	*count(void *arg)
{
	int		i;
	char	*name;
	arg_t	*args;

	args = (arg_t *)arg;
	name = args->name;
	pthread_mutex_lock(args->mutex);
	for (i = 0; i < 10; i++)
	{
		printf("%s cnt: %d\n", name, cnt);
		cnt++;
		usleep(10);
	}
	pthread_mutex_unlock(args->mutex);
	return NULL;
}

int	main(void)
{
	pthread_t		thread1;
	pthread_t		thread2;
	pthread_mutex_t	mutex;
	arg_t			*args1;
	arg_t			*args2;

	args1 = malloc(sizeof(arg_t *));
	args2 = malloc(sizeof(arg_t *));
	int	rt = pthread_mutex_init(&mutex, NULL);
	if (rt != 0)
		return (1);
	args1->name = "thread1";
	args1->mutex = &mutex;
	args2->name = "thread2";
	args2->mutex = &mutex;

	pthread_create(&thread1, NULL, count, args1);
	pthread_create(&thread2, NULL, count, args2);

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	pthread_mutex_destroy(&mutex);
}
