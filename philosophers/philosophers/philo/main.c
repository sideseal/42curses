/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:14:02 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/01 22:56:43 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	_abort(char *string, t_share *share, t_philo **philos)
{
	free(share->forks);
	free(share->fork_locks);
	free(*philos);
	printf("\x1b[31m" "Abort: " "\x1b[0m");
	printf("%s\n", string);
	return (1);
}

int	main(int argc, char **argv)
{
	t_args	args;
	t_share	share;
	t_philo	*philos;

	if (argc < 5 || argc > 6 || valid_input(argv) == FALSE)
		return (printf(USAGE1 USAGE2) * 0 + 1);
	init_struct_args(&args, argv);
	if (init_all_malloc(&share, &philos, args.philo_num) == FALSE)
		return (_abort("initialize malloc failed", &share, &philos));
	if (init_all_mutex(&share, args.philo_num) == FALSE)
		return (_abort("initialize mutex failed", &share, &philos));
	init_struct_share(&share, args);
	init_struct_philo(&philos, &share, args);
	if (simulate(philos, &share) == FALSE)
		return (_abort("execute simulation failed", &share, &philos));
	free(share.forks);
	free(share.fork_locks);
	free(philos);
	return (0);
}
