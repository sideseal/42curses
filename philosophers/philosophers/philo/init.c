/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:08:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/17 00:37:29 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_malloc_elems(t_shared *shared, t_philo **philos, char *arg)
{
	int	num;

	*philos = 0;
	shared->forks = 0;
	shared->forks_mutex = 0;
	shared->philo_mutex = 0;
	num = atoi_only_unsigned(arg);
	*philos = malloc(sizeof(t_philo) * num);
	shared->forks = malloc(sizeof(int) * num);
	shared->forks_mutex = malloc(sizeof(pthread_mutex_t) * num);
	shared->philo_mutex = malloc(sizeof(pthread_mutex_t) * num);
	if (*philos == 0 || shared->forks == 0 \
		|| shared->forks_mutex == 0 || shared->philo_mutex == 0)
		return (-1);
	if (memset(*philos, 0, sizeof(t_philo) * num) == 0 \
		|| memset(shared->forks, 0, sizeof(int) * num) == 0 \
		|| memset(shared->forks_mutex, 0, sizeof(pthread_mutex_t) * num) == 0 \
		|| memset(shared->philo_mutex, 0, sizeof(pthread_mutex_t) * num) == 0)
		return (-1);
	return (0);
}

int	init_param(t_param *param, char **argv)
{
	param->philo_num = atoi_only_unsigned(argv[1]);
	param->philo_time_die = atoi_only_unsigned(argv[2]);
	param->philo_time_eat = atoi_only_unsigned(argv[3]);
	param->philo_time_sleep = atoi_only_unsigned(argv[4]);
	if (argv[5] != 0)
		param->philo_must_eat = atoi_only_unsigned(argv[5]);
	else
		param->philo_must_eat = -1;
	return (0);
}

int	init_shared(t_shared *shared, t_param param)
{
	int	i;

	shared->param = param;
	i = -1;
	while (++i < param.philo_num)
		if (pthread_mutex_init(&(shared->forks_mutex)[i], 0))
			return (clear_mutex_array(shared->forks_mutex, i));
	i = -1;
	while (++i < param.philo_num)
	{
		if (pthread_mutex_init(&(shared->philo_mutex)[i], 0))
		{
			clear_mutex_array(shared->forks_mutex, param.philo_num);
			return (clear_mutex_array(shared->philo_mutex, i));
		}
	}
	if (pthread_mutex_init(&(shared->shared_mutex), 0))
		return (clear_all_shared_mutex(shared));
	shared->philo_is_dead = 0;
	shared->eat_finish = 0;
	shared->start_time = get_current_time();
	if (shared->start_time < 0)
		return (-1);
	return (0);
}

int	init_philos(t_shared *shared, t_param param, t_philo **philos)
{
	int	i;

	i = -1;
	while (++i < param.philo_num)
	{
		(*philos)[i].shared = shared;
		(*philos)[i].fork[0] = &(shared->forks[i]);
		(*philos)[i].fork_mutex[0] = &(shared->forks_mutex[i]);
		if (param.philo_num > 1)
		{
			(*philos)[i].fork[1] = &(shared->forks[(i + 1) % param.philo_num]);
			(*philos)[i].fork_mutex[1] = \
				&(shared->forks_mutex[(i + 1) % param.philo_num]);
		}
		(*philos)[i].philo_mutex = &(shared->philo_mutex[i]);
		(*philos)[i].philo_thread = 0;
		(*philos)[i].philo_name = i + 1;
		(*philos)[i].philo_count_eat = param.philo_must_eat;
		(*philos)[i].philo_last_eat = get_current_time();
		if ((*philos)[i].philo_last_eat < 0)
			return (clear_all_shared_mutex(shared));
	}
	return (0);
}
