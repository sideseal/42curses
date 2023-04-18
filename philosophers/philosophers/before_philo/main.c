/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:42:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/17 21:46:18 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	_abort(char *string, t_shared *shared, t_philo **philos)
{
	free(*philos);
	free(shared->forks);
	free(shared->forks_mutex);
	free(shared->philo_mutex);
	printf("\x1b[31m" "Abort: " "\x1b[0m");
	printf("%s\n", string);
	return (1);
}

static void	*_lonely_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_mutex[0]);
	*(philo->fork[0]) = 1;
	philo_print(philo, "has taken a fork");
	philo_sleep(philo->shared->param.philo_time_die);
	philo_print(philo, "died");
	pthread_mutex_unlock(philo->fork_mutex[0]);
	return ((void *)0);
}

int	finished(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(&(philo->shared->shared_mutex));
	if (philo->shared->param.philo_must_eat > 0 && philo->philo_count_eat == 0)
	{
		philo->shared->philo_eat_finish++;
		pthread_mutex_unlock(&(philo->shared->shared_mutex));
		return (1);
	}
	dead = philo->shared->philo_is_dead;
	pthread_mutex_unlock(&(philo->shared->shared_mutex));
	return (dead);
}

static void	*_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&(philo->shared->shared_mutex));
	pthread_mutex_unlock(&(philo->shared->shared_mutex));
	if (philo->shared->param.philo_num == 1)
		return (_lonely_philo(philo));
	pthread_mutex_lock(philo->philo_mutex);
	philo->philo_last_eat = get_current_time();
	pthread_mutex_unlock(philo->philo_mutex);
	if (philo->philo_name & 1)
	{
		thinking(philo);
		philo_sleep(philo->shared->param.philo_time_eat);
	}
	while (!finished(philo))
	{
		if (!eating(philo))
			break ;
		sleeping(philo);
		thinking(philo);
	}
	return ((void *)0);
}

int	finished_monitoring(t_shared *shared)
{
	pthread_mutex_lock(&(shared->shared_mutex));
	if (shared->philo_is_dead || (shared->philo_eat_finish == shared->param.philo_num))
	{
		pthread_mutex_unlock(&(shared->shared_mutex));
		return (1);
	}
	pthread_mutex_unlock(&(shared->shared_mutex));
	return (0);
}

void	_monitoring(t_philo *philos, t_shared *shared)
{
	int	i;
	int	timestamp;

	while (!finished_monitoring(shared))
	{
		i = -1;
		while (++i < shared->param.philo_num)
		{
			pthread_mutex_lock(philos[i].philo_mutex);
			if (shared->param.philo_must_eat < 0 && philos[i].philo_count_eat != 0)
			{
				if (get_current_time() - philos[i].philo_last_eat > shared->param.philo_time_die)
				{
					pthread_mutex_lock(&(shared->shared_mutex));
					timestamp = (int)(get_current_time() - shared->start_time);
					shared->philo_is_dead = 1;
					printf("%d %d dead\n", timestamp, philos[i].philo_name);
					pthread_mutex_unlock(&(shared->shared_mutex));
					pthread_mutex_unlock(philos[i].philo_mutex);
					return ;
				}
			}
			pthread_mutex_unlock(philos[i].philo_mutex);
		}
		usleep(500);
	}
}

static int	_simulation(t_philo *philos, t_shared *shared)
{
	int	i;

	pthread_mutex_lock(&(shared->shared_mutex));
	i = -1;
	while (++i < shared->param.philo_num)
		if (pthread_create(&(philos[i].philo_thread), NULL, \
			_routine, (void *)&(philos[i])) != 0)
			return (clear_and_detach_all_thread(philos, shared));
	shared->start_time = get_current_time();
	pthread_mutex_unlock(&(shared->shared_mutex));
	_monitoring(philos, shared);
	i = -1;
	while (++i < shared->param.philo_num)
		if (pthread_join(philos[i].philo_thread, NULL) != 0)
			return (clear_and_detach_all_thread(philos, shared));
	clear_all_shared_mutex(shared);
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
		return (_abort("initialize malloc failed", &shared, &philos));
	if (init_param(&param, argv) != 0)
		return (_abort("initialize param failed", &shared, &philos));
	if (init_shared(&shared, param) != 0)
		return (_abort("initialize shared failed", &shared, &philos));
	if (init_philos(&shared, param, &philos) != 0)
		return (_abort("initialize philos failed", &shared, &philos));
	if (_simulation(philos, &shared) != 0)
		return (_abort("execute simulation failed", &shared, &philos));
	free(philos);
	free(shared.forks);
	free(shared.forks_mutex);
	free(shared.philo_mutex);
	return (0);
}
