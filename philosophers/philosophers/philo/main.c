/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:42:05 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/12 23:57:23 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_abort(char *string)
{
	printf("%s\n", string);
	return (1);
}

static void	*_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->philo_name & 1)
	{
		philo_sleep(philo->shared->param.philo_time_eat / philo->shared->param.philo_num);
		thinking(philo);
	}
	// check must_eat_count
	while (!philo->shared->philo_is_dead)
	{
		if (philo->philo_count_eat == philo->shared->param.philo_must_eat)
			break ;
		pick_up_forks(philo);
		eating(philo);
		put_down_forks(philo);
		sleeping(philo);
		thinking(philo);
	}
	return ((void *)0);
}

static void	_stop_simulation_by_cond(t_philo *philos, t_shared shared)
{
	int	i;
	int	timestamp;
	int	flag;

	flag = 1;
	while (flag)
	{
		i = 0;
		while (i < shared.param.philo_num)
		{
			if (get_current_time() - philos[i].philo_last_eat >= shared.param.philo_time_die)
			{
				timestamp = (int)(get_current_time() - philos[i].shared->start_time);
				pthread_mutex_lock(&(philos[i].shared->shared_mutex));
				printf("%d %d died\n", timestamp, philos[i].philo_name);
				//pthread_mutex_unlock(&(philos[i].shared->shared_mutex)); 
				// 음... 만약 플래그가 세워지면, 다른 쓰레드가 print에 접근하지 않도록 해야한다.
				flag = 0;
				shared.philo_is_dead = 1;
				break ;
			}
			i++;
		}
		//usleep(100);
	}
}


// need exception
static void	_simulation(t_philo *philos, t_shared shared)
{
	int		i;

	i = 0;
	while (i < shared.param.philo_num)
	{
		if (pthread_create(&(philos[i].philo_thread), NULL, \
			_routine, (void *)&(philos[i])) != 0)
		{
			detach_all_thread(philos,shared);
			return ;
		}
		i++;
	}
	_stop_simulation_by_cond(philos, shared);
	i = 0;
	while (i < shared.param.philo_num)
	{
		if (pthread_join(philos[i].philo_thread, NULL) != 0)
			return ; // detach all?
		i++;
	}
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
	if (argc < 5 || argc > 6 || !check_valid_input(argv))
		return (philo_abort(USAGE_MESSAGE));
	if (init_param(&param, argv) < 0)
		return (philo_abort("Cannot initialize param structure. Abort."));
	if (init_shared(&shared, param) < 0)
	{
		free(shared.forks);
		free(shared.forks_mutex);
		return (philo_abort("Cannot initialize shared structure. Abort."));
	}
	if (init_philos(&philos, param, &shared) < 0)
	{
		free(philos);
		free(shared.forks);
		free(shared.forks_mutex);
		return (philo_abort("Cannot initialize philos structure. Abort."));
	}
	_simulation(philos, shared);
	// destroy mutex
	//ft_free_both(resources.forks, resources.forks_mutex);
	//free(philos);
	return (0);
}
