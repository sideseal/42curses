/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:08:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/06 22:28:05 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_context(t_context *context, char **argv)
{
	context->philo_num = philo_atoi(argv[1]);
	context->philo_time_die = philo_atoi(argv[2]);
	context->philo_time_eat = philo_atoi(argv[3]);
	context->philo_time_sleep = philo_atoi(argv[4]);
	if (context->philo_num < 0 || context->philo_time_die < 0 \
		|| context->philo_time_eat < 0 || context->philo_time_sleep < 0)
		return (-1);
	if (argv[5] != 0)
	{
		context->philo_must_eat = philo_atoi(argv[5]);
		if (context->philo_must_eat < 0)
			return (-1);
	}
	else
		context->philo_must_eat = -1;
	return (0);
}

// check execption
// need to free forks
int	init_resources(t_resource *resources, t_context context)
{
	int				*forks;
	int				i;
	pthread_mutex_t	*forks_mutex;

	forks = malloc(sizeof(int) * context.philo_num);
	if (forks == 0 || memset(forks, 0, sizeof(int) * context.philo_num) == 0)
		return (ft_free_both(forks, 0));
	resources->forks = forks;
	forks_mutex = malloc(sizeof(pthread_mutex_t) * context.philo_num);
	if (forks_mutex == 0 \
		|| memset(forks_mutex, 0, sizeof(pthread_mutex_t) * context.philo_num) == 0)
		return (ft_free_both(forks, forks_mutex));
	resources->forks_mutex = forks_mutex;
	i = 0;
	while (i < context.philo_num)
	{
		if (pthread_mutex_init(&(resources->forks_mutex)[i], NULL))
			return (ft_free_both(forks, forks_mutex));
		i++;
	}
	if (pthread_mutex_init(&(resources->print_mutex), NULL))
		return (ft_free_both(forks, forks_mutex));
	return (0);
}

// check exception
// need to free philos
int	init_philos(t_philo **philos, t_context context, t_resource resources)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * context.philo_num);
	if (*philos == 0)
		return (ft_free_both(philos, NULL));
	i = 0;
	while (i < context.philo_num)
	{
		(*philos)[i].philo_thread = 0;
		(*philos)[i].philo_name = i + 1;
		(*philos)[i].resources = resources;
		(*philos)[i].fork[0] = &(resources.forks[i]);
		(*philos)[i].fork[1] = &(resources.forks[(i + 1) % context.philo_num]);
		(*philos)[i].fork_mutex[0] = &(resources.forks_mutex[i]);
		(*philos)[i].fork_mutex[1] = \
			&(resources.forks_mutex[(i + 1) % context.philo_num]);
		(*philos)[i].context = context;
		(*philos)[i].count_eat = 0;
		(*philos)[i].philo_is_dead = 0;
		i++;
	}
	return (0);
}
