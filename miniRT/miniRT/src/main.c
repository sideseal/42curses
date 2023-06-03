/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:40:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/03 23:25:17 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	_print_usage(void)
{
	printf("Usage: ./miniRT <rt_file>\n");
	printf("<rt_file> should be a file with the '.rt' extension.\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || check_file_ext(argv[1]) == FALSE)
		return (_print_usage());
	data = init_data();
	read_file(data, argv[1]);
	render(data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_hook(data->win, RED_CROSS, 0, exit_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
