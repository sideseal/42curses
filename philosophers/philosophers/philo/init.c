/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:08:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/03/31 23:18:18 by gychoi           ###   ########.fr       */
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
}

// check execption
// need to free forks
void	init_resources(t_resource *resources, t_context context)
{
	int	*forks;

	forks = malloc(sizeof(int) * context.philo_num);
	if (forks == 0 || memset(forks, 0, sizeof(int) * context.philo_num) == 0)
		return ;
	resources->forks = forks;
	if (pthread_mutex_init(&(resources->mutex_print), NULL))
		return ;
	if (pthread_mutex_init(&(resources->mutex_forks), NULL))
		return ;
}

// check exception
// need to free philos
void	init_philos(t_philo **philos, t_context context, t_resource resources)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * context.philo_num);
	if (*philos == 0)
		return ;
	i = 0;
	while (i < context.philo_num)
	{
		(*philos)[i].philo_thread = 0;
		(*philos)[i].philo_name = i + 1;
		(*philos)[i].resources = resources;
		(*philos)[i].fork[0] = &(resources.forks[i]);
		(*philos)[i].fork[1] = &(resources.forks[(i + 1) % context.philo_num]);
		(*philos)[i].time_die = context.philo_time_die;
		(*philos)[i].time_eat = context.philo_time_eat;
		(*philos)[i].time_sleep = context.philo_time_sleep;
		(*philos)[i].count_eat = 0;
		(*philos)[i].philo_must_eat = context.philo_must_eat;
		(*philos)[i].philo_is_dead = 0;
		i++;
	}
}
