/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 21:08:54 by gychoi            #+#    #+#             */
/*   Updated: 2023/03/28 21:37:24 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_context	*init_context(char *arg, char *arg4)
{
	t_context	*new;

	new = malloc(sizeof(t_context *));
	if (new == 0)
		return (0);
	new->philo_num = philo_atoi(arg);
	new->philo_dead = 0;
	if (arg4 != 0)
		new->philo_must_eat = philo_atoi(arg4);
	else
		new->philo_must_eat = -1;
	return (new);
}

t_philo	*init_philo(char *arg1, char *arg2, char *arg3)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo *));
	if (new == 0)
		return (0);
	new->fork[0] = 0;
	new->fork[1] = 0;
	new->time_die = philo_atoi(arg1);
	new->time_eat = philo_atoi(arg2);
	new->time_sleep = philo_atoi(arg3);
	new->count_eat = 0;
	return (new);
}
