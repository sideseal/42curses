/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 19:11:22 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/18 20:39:03 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_struct_args(t_args *args, char **argv)
{
	args->philo_num = atoi_only_unsigned(argv[1]);
	args->philo_time_die = atoi_only_unsigned(argv[2]);
	args->philo_time_eat = atoi_only_unsigned(argv[3]);
	args->philo_time_sleep = atoi_only_unsigned(argv[4]);
	if (argv[5] != 0)
		args->philo_must_eat = atoi_only_unsigned(argv[5]);
	else
		args->philo_must_eat = -1;
}

void	init_struct_share(t_share *share, t_args args)
{
	share->args = args;
	share->fork_locks = share->fork_locks;
	share->share_lock = share->share_lock;
	share->stop = FALSE;
	share->philo_start_time = 0;
}

void	init_struct_philo(t_philo **philos, t_share *share, t_args args)
{
	int	i;

	i = 0;
	while (i < args.philo_num)
	{
		(*philos)[i].share = share;
		(*philos)[i].fork_lock[0] = &(share->fork_locks[i]);
		if (args.philo_num == 1)
			(*philos)[i].fork_lock[1] = 0;
		else
			(*philos)[i].fork_lock[1] = \
			&(share->fork_locks[(i + 1) % args.philo_num]);
		(*philos)[i].philo_thread = 0;
		(*philos)[i].philo_id = i + 1;
		(*philos)[i].philo_count_eat = args.philo_must_eat;
		(*philos)[i].philo_time_last_eat = 0;
		i++;
	}
}

int	init_all_mutex(t_share *share, int philo_num)
{
	int	i;

	i = 0;
	while (i < philo_num)
	{
		if (pthread_mutex_init(&(share->fork_locks)[i], 0) != 0)
			return (clear_mutex_array(share->fork_locks, i));
		i++;
	}
	if (pthread_mutex_init(&(share->share_lock), 0) != 0)
		return (clear_all_mutex(share));
	return (TRUE);
}

int	init_all_malloc(t_share *share, t_philo **philos, int philo_num)
{
	*philos = 0;
	share->fork_locks = 0;
	*philos = malloc(sizeof(t_philo) * philo_num);
	share->fork_locks = malloc(sizeof(pthread_mutex_t) * philo_num);
	if (*philos == 0 || share->fork_locks == 0)
		return (FALSE);
	if (!memset(*philos, 0, sizeof(t_philo) * philo_num) \
		|| !memset(share->fork_locks, 0, sizeof(pthread_mutex_t) * philo_num))
		return (FALSE);
	return (TRUE);
}
