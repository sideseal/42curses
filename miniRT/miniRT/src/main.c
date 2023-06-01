/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gychoi <gychoi@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 18:40:29 by gychoi            #+#    #+#             */
/*   Updated: 2023/06/01 23:28:09 by gychoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_error(const char *string)
{
	printf("Error\n");
	printf("%s\n", string);
	exit(1);
}

void	check_leaks(void)
{
	system("leaks --list -- miniRT");
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2 || check_file_ext(argv[1]) == FALSE)
	{
		printf("Usage: ./miniRT <rt_file>\n");
		printf("<rt_file> should be a file with the '.rt' extension.\n");
		return (1);
	}
	data = init_data();
	atexit(check_leaks);
	return (0);
}
