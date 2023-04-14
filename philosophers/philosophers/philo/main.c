/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:42:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/15 01:51:42 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	_philo_abort(char *string, t_shared *shared, t_philo **philos)
{
	free(*philos);
	free(shared->forks);
	free(shared->forks_mutex);
	free(shared->philo_mutex);
	printf("\x1b[31m" "Abort: " "\x1b[0m");
	printf("%s\n", string);
	return (1);
}

int	is_dead(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&(philo->shared->shared_mutex));
	dead = philo->shared->philo_is_dead;
	pthread_mutex_unlock(&(philo->shared->shared_mutex));
	return (dead);
}

static void	*_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->shared->param.philo_num == 1)
	{
		// 수정 필요
		pthread_mutex_lock(philo->fork_mutex[0]);
		philo_print(philo, "has taken a fork");
		philo_sleep(philo->shared->param.philo_time_die);
		pthread_mutex_unlock(philo->fork_mutex[0]);
		return ((void *)0);
	}
	if (philo->philo_name % 2)
		philo_sleep(philo->shared->param.philo_time_eat / 2);
	while (!is_dead(philo) && --philo->philo_count_eat != 0)
	{
		thinking(philo);
		if (!pick_up_forks(philo))
			break ;
		if (!try_eating(philo))
			break ;
		put_down_forks(philo);
		sleeping(philo);
	}
	return ((void *)0);
}

static int	_simulation(t_philo *philos, t_shared *shared)
{
	int	i;

	i = -1;
	pthread_mutex_lock(&(shared->shared_mutex));
	while (++i < shared->param.philo_num)
		if (pthread_create(&(philos[i].philo_thread), NULL, \
			_routine, (void *)&(philos[i])) != 0)
			return (clear_and_detach_all_thread(philos, shared));
	pthread_mutex_unlock(&(shared->shared_mutex));
	i = -1;
	while (++i < shared->param.philo_num)
		if (pthread_join(philos[i].philo_thread, NULL) != 0)
			return (clear_and_detach_all_thread(philos, shared));
	clear_all_mutex(shared);
	return (0);
}

void	check_leaks(void)
{
	// need to delete
	system("leaks philo");
}

int	main(int argc, char **argv)
{
	t_param			param;
	t_philo			*philos;
	t_shared		shared;

	//atexit(check_leaks);
	if (argc < 5 || argc > 6 || check_valid_input(argv) != 0)
		return (printf(USAGE_MESSAGE) * 0 + 1);
	if (init_malloc_elems(&shared, &philos, argv[1]) != 0)
		return (_philo_abort("initialize malloc failed", &shared, &philos));
	if (init_param(&param, argv) != 0)
		return (_philo_abort("initialize param failed", &shared, &philos));
	if (init_shared(&shared, param) != 0)
		return (_philo_abort("initialize shared failed", &shared, &philos));
	if (init_philos(&shared, param, &philos) != 0)
		return (_philo_abort("initialize philos failed", &shared, &philos));
	if (_simulation(philos, &shared) != 0)
		return (_philo_abort("execute simulation failed", &shared, &philos));
	free(philos);
	free(shared.forks);
	free(shared.forks_mutex); //arr
	free(shared.philo_mutex);
	return (0);
}
