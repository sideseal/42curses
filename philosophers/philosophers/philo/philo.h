/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:13:11 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/21 21:19:44 by gychoi           ###   ########.fr       */
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

# define TRUE 1
# define FALSE 0
# define USAGE1 "Usage: ./philo number_of_philosophers time_to_die time_to_eat"
# define USAGE2 " time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

typedef struct s_args
{
	int	philo_num;
	int	philo_time_die;
	int	philo_time_eat;
	int	philo_time_sleep;
	int	philo_must_eat;
}	t_args;

typedef struct s_share
{
	t_args			args;
	int				*forks;
	pthread_mutex_t	*fork_locks;
	pthread_mutex_t	share_lock;
	int				stop;
	long long		philo_start_time;
}	t_share;

typedef struct s_philo
{
	t_share			*share;
	int				*forks[2];
	pthread_mutex_t	*fork_lock[2];
	pthread_t		philo_thread;
	int				philo_id;
	int				philo_count_eat;
	long long		philo_time_last_eat;
	int				error;
}	t_philo;

void		philo_print(t_philo *philo, char *str);
int			philo_sleep(long long wait_time, t_philo *philo);
void		philo_dead(t_philo *philo);
int			check_philo_dead(t_philo *philo);
long long	get_current_time(t_philo *philo);

int			clear_mutex_array(pthread_mutex_t *mutex_array, int index);
int			clear_all_mutex(t_share *share);
int			clear_and_detach_all_thread(t_philo *philos, t_share *share);

void		init_struct_args(t_args *args, char **argv);
void		init_struct_share(t_share *share, t_args args);
void		init_struct_philo(t_philo **philos, t_share *share, t_args args);
int			init_all_mutex(t_share *share, int philo_num);
int			init_all_malloc(t_share *share, t_philo **philos, int philo_num);

void		lock(pthread_mutex_t *mutex, t_philo *philo);
void		unlock(pthread_mutex_t *mutex, t_philo *philo);
int			atoi_only_unsigned(char *n);
int			valid_input(char **argv);

int			simulate(t_philo *philos, t_share *share);

#endif
