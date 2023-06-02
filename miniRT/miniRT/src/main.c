/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:40:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/02 22:09:52 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_leaks(void)
{
	// 지우는거 잊지 말기
	system("leaks --list -- miniRT");
}

static int	_print_usage(void)
{
	printf("Usage: ./miniRT <rt_file>\n");
	printf("<rt_file> should be a file with the '.rt' extension.\n");
	printf("Each type of information from an elements in <rt_file>"
			"are separated by one or more spaces.\n");
	return (1);
}

void	print_error(char *string, void *data)
{
	printf("Error\n");
	perror(string);
	free_struct(data);
	atexit(check_leaks);
	exit(1);
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
	free_struct(data);
	atexit(check_leaks);
	return (0);
}
