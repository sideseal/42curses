/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:23:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/04/07 17:09:41 by gychoi           ###   ########.fr       */
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

typedef struct s_context
{
	int	philo_num;
	int	philo_time_die;
	int	philo_time_eat;
	int	philo_time_sleep;
	int	philo_must_eat;
}	t_context;

typedef struct s_resource
{
	int				*forks;
	pthread_mutex_t	*forks_mutex;
	pthread_mutex_t	print_mutex;
}	t_resource;

typedef struct s_philo
{
	pthread_t		philo_thread;
	t_resource		resources;
	int				philo_name;
	int				*fork[2];
	pthread_mutex_t	*fork_mutex[2];
	t_context		context;
	int				philo_count_eat;
	int				philo_is_dead;
}	t_philo;

long long	get_millisecond(void);
int			ft_free_both(void *ptr1, void *ptr2);
int			philo_atoi(char *num);
int			check_valid_input(char **argv);

int			init_context(t_context *context, char **argv);
int			init_resources(t_resource *resources, t_context context);
int			init_philos(t_philo **philos, t_context context, \
			t_resource resources);

void		simulation(t_context context, t_philo *philos, \
			t_resource resources);

#endif
