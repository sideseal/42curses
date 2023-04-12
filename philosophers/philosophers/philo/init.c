/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:08:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/12 23:52:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_param(t_param *param, char **argv)
{
	param->philo_num = philo_atoi(argv[1]);
	param->philo_time_die = philo_atoi(argv[2]);
	param->philo_time_eat = philo_atoi(argv[3]);
	param->philo_time_sleep = philo_atoi(argv[4]);
	if (param->philo_num < 0 || param->philo_time_die < 0 \
		|| param->philo_time_eat < 0 || param->philo_time_sleep < 0)
		return (-1);
	if (argv[5] != 0)
	{
		param->philo_must_eat = philo_atoi(argv[5]);
		if (param->philo_must_eat < 0)
			return (-1);
	}
	else
		param->philo_must_eat = -1;
	return (0);
}

static int	_init_resources(t_shared *shared, t_param param)
{
	int				*forks;
	int				i;
	pthread_mutex_t	*forks_mutex;

	forks = malloc(sizeof(int) * param.philo_num);
	if (forks == 0 || memset(forks, 0, sizeof(int) * param.philo_num) == 0)
		return (-1);
	shared->forks = forks;
	forks_mutex = malloc(sizeof(pthread_mutex_t) * param.philo_num);
	if (forks_mutex == 0 || memset(forks_mutex, 0, \
		sizeof(pthread_mutex_t) * param.philo_num) == 0)
		return (-1);
	shared->forks_mutex = forks_mutex;
	i = -1;
	while (++i < param.philo_num)
		if (pthread_mutex_init(&(shared->forks_mutex)[i], 0))
			return (clear_forks_mutex(shared, i));
	if (pthread_mutex_init(&(shared->shared_mutex), 0))
		return (clear_forks_mutex(shared, i));
	return (0);
}

int	init_shared(t_shared *shared, t_param param)
{
	shared->param = param;
	shared->forks = 0;
	shared->forks_mutex = 0;
	shared->philo_is_dead = 0;
	shared->start_time = get_current_time();
	if (shared->start_time < 0)
		return (-1);
	if (_init_resources(shared, param) < 0)
		return (-1);
	return (0);
}

int	init_philos(t_philo **philos, t_param param, t_shared *shared)
{
	int	i;

	*philos = malloc(sizeof(t_philo) * param.philo_num);
	if (*philos == 0)
		return (clear_all_mutex(shared));
	i = -1;
	while (++i < param.philo_num)
	{
		(*philos)[i].shared = shared;
		(*philos)[i].fork[0] = &(shared->forks[i]);
		(*philos)[i].fork[1] = &(shared->forks[(i + 1) % param.philo_num]);
		(*philos)[i].fork_mutex[0] = &(shared->forks_mutex[i]);
		(*philos)[i].fork_mutex[1] = \
			&(shared->forks_mutex[(i + 1) % param.philo_num]);
		(*philos)[i].philo_thread = 0;
		(*philos)[i].philo_name = i + 1;
		(*philos)[i].philo_count_eat = 0;
		(*philos)[i].philo_last_eat = get_current_time();
		if ((*philos)[i].philo_last_eat < 0)
			return (clear_all_mutex(shared));
	}
	return (0);
}
