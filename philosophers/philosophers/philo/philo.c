/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:11:15 by gychoi            #+#    #+#             */
/*   Updated: 2023/03/28 21:41:09 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_context	*context;
	t_philo		*philo;

	if (argc < 5 || argc > 6 || !check_valid_input(argv))
	{
		printf("Usage: ./philo number_of_philosophers time_to_die time_to_eat"
			" time_to_sleep [number_of_times_each_philosopher_must_eat]");
		return (1);
	}
	context = init_context(argv[1], argv[5]);
	philo = init_philo(argv[2], argv[3], argv[4]);
	printf("%d, %d, %d\n", context->philo_num, context->philo_dead, context->philo_must_eat);
	printf("[%d, %d], %d, %d, %d, %d\n", philo->fork[0], philo->fork[1], philo->time_die, philo->time_eat, philo->time_sleep, philo->count_eat);
	return (0);
}
