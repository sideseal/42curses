/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:23:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/11 23:22:14 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_param
{
	int	philo_num;
	int	philo_time_die;
	int	philo_time_eat;
	int	philo_time_sleep;
	int	philo_must_eat;
}	t_param;

typedef struct s_shared
{
	int				*forks;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	print_mutex;
}	t_shared;

typedef struct s_philo
{
	t_shared		shared;
	int				*fork[2];
	pthread_mutex_t	*fork_mutex[2];
	t_param			param;
	int				philo_name;
	pthread_t		philo_thread;
	int				philo_count_eat;
	int				philo_is_dead;
}	t_philo;

long long	get_millisecond(void);
int			philo_abort(char *string);
int			philo_atoi(char *num);
int			check_valid_input(char **argv);

int			init_param(t_param *param, char **argv);
int			init_shared(t_shared *shared, t_param param);
int			init_philos(t_philo **philos, t_param param, t_shared shared);

void		simulation(t_param param, t_philo *philos, t_shared shared);

#endif
