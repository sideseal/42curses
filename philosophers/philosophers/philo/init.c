/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:08:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/03/30 22:12:58 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_context(t_context *context, char **argv)
{
	context->philo_num = philo_atoi(argv[1]);
	context->philo_time_die = philo_atoi(argv[2]);
	context->philo_time_eat = philo_atoi(argv[3]);
	context->philo_time_sleep = philo_atoi(argv[4]);
	if (argv[5] != 0)
		context->philo_must_eat = philo_atoi(argv[5]);
	else
		context->philo_must_eat = -1;
	context->philo_is_dead = 0;
}

// check exception
void	init_philo(t_philo **philosophers, t_context context)
{
	int	*forks;
	int	i;

	forks = malloc(sizeof(int) * context.philo_num);
	if (forks == 0 || memset(forks, 0, sizeof(int) * context.philo_num) == 0)
		return ;
	*philosophers = malloc(sizeof(t_philo) * context.philo_num);
	if (*philosophers == 0)
		return ;
	i = 0;
	while (i < context.philo_num)
	{
		(*philosophers)[i].philo = 0;
		(*philosophers)[i].philo_name = i + 1;
		(*philosophers)[i].fork[0] = &forks[i];
		if (i + 1 < context.philo_num)
			(*philosophers)[i].fork[1] = &forks[i + 1];
		else
			(*philosophers)[i].fork[1] = &forks[0];
		(*philosophers)[i].time_die = context.philo_time_die;
		(*philosophers)[i].time_eat = context.philo_time_eat;
		(*philosophers)[i].time_sleep = context.philo_time_sleep;
		(*philosophers)[i].count_eat = 0;
		(*philosophers)[i].forks = forks; // need to delete
		i++;
	}
}
