/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:23:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/17 20:20:00 by gychoi           ###   ########.fr       */
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

# define USAGE_MESSAGE "Usage: ./philo number_of_philosophers time_to_die \
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

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
	t_param			param;
	int				*forks;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	*philo_mutex;
	pthread_mutex_t	shared_mutex;
	int				philo_eat_finish;
	int				philo_is_dead;
	int				eat_finish;
	long long		start_time;
}	t_shared;

typedef struct s_philo
{
	t_shared		*shared;
	int				*fork[2];
	pthread_mutex_t	*fork_mutex[2];
	pthread_mutex_t	*philo_mutex;
	int				philo_name;
	pthread_t		philo_thread;
	int				philo_count_eat;
	long long		philo_last_eat;
}	t_philo;

long long	get_current_time(void);
int			atoi_only_unsigned(char *num);
int			check_valid_input(char **argv);

int			init_malloc_elems(t_shared *shared, t_philo **philos, char *arg);
int			init_param(t_param *param, char **argv);
int			init_shared(t_shared *shared, t_param param);
int			init_philos(t_shared *shared, t_param, t_philo **philos);

int			clear_mutex_array(pthread_mutex_t *mutex_array, int index);
int			clear_all_shared_mutex(t_shared *shared);
int			clear_and_detach_all_thread(t_philo *philos, t_shared *shared);

void		philo_print(t_philo *philo, char *str);
void		philo_sleep(long long wait_time);
int			philo_dead(t_philo *philo);

int			eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);
#endif
