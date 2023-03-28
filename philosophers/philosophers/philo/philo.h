/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:23:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/03/28 21:41:24 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct	s_context
{
	int	philo_num;
	int	philo_dead;
	int	philo_must_eat;
}	t_context;

typedef struct	s_philo
{
	int	fork[2];
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	count_eat;
}	t_philo;

int			check_valid_input(char **argv);
int			philo_atoi(char *num);
t_context	*init_context(char *arg, char *arg4);
t_philo		*init_philo(char *arg1, char *arg2, char *arg3);

#endif
