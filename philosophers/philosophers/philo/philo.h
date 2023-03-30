/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:23:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/03/30 22:24:52 by gychoi           ###   ########.fr       */
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

typedef struct	s_context
{
	int	philo_num;
	int	philo_time_die;
	int	philo_time_eat;
	int	philo_time_sleep;
	int	philo_must_eat;
	int	philo_is_dead;
}	t_context;

typedef struct	s_philo
{
	pthread_t	philo;
	int			philo_name;
	int			*fork[2];
	int			time_die;
	int			time_eat;
	int			time_sleep;
	int			count_eat;
	int			*forks; // need to delete
}	t_philo;

int			check_valid_input(char **argv);
int			philo_atoi(char *num);
void		init_context(t_context *context, char **argv);
void		init_philo(t_philo **philosophers, t_context context);

#endif
